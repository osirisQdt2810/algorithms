---
description: Commit study progress — daily LeetCode (main repo) + course lessons/homework/revision (submodules), one commit per unit, on the correct per-repo branch; [lc]/[problem] flags also publish those branches as auto-merge PRs
argument-hint: "[optional flags: [lc] [problem] to rebase+push+PR those targets] [optional: paths/names to restrict scope, e.g. 2026_07_06 | lesson-06-graph | 01-two-pointers-sliding-window; else all pending]"
allowed-tools: Bash(git:*), Bash(ls:*), Bash(gh:*), Bash(pre-commit:*), Bash(g++:*), Read, Edit, WebFetch
---

Commit uncommitted study work across **four targets in three repos** (the main repo hosts both Target A and Target D), each with its own scope, branch convention, and commit-message format. This supersedes the old `commit-daily-leetcode` command and fully covers it (the daily-LeetCode case is Target A below).

The two `courses/*` folders are **git submodules** — commit *inside* the submodule with `git -C courses/<name> …`, on that submodule's own branch. They are independent repos.

## Targets

| # | Repo | Scope (only these paths) | Unit = one commit |
|---|------|--------------------------|-------------------|
| A | `.` (main repo `dsa-journey`) | `src/leetcode/daily/YYYY_MM_DD/` | one **date folder** |
| B | `courses/dsa-mentorship` (submodule) | `lesson-NN-<topic>/` and `lesson-NN-<topic>/hw/` | one **problem** (its `X. *.cpp` + matching `input_X.txt`) |
| C | `courses/fse13-faang` (submodule) | `NN-<topic>/{homework,livecoding,revision}/` | one **problem** file (+ any sibling input) |
| D | `.` (main repo `dsa-journey`) | `src/leetcode/problems/<topic>/` | one **problem** file `NNNN. *.cpp` (+ any sibling input) — a self-study *review series* |

- `$ARGUMENTS` may contain the publish flags `[lc]` / `[problem]` (see **Push & PR flags** below) — strip them first; the remaining tokens are scope filters.
- If the remaining `$ARGUMENTS` name specific date folders / lesson folders / topic folders, restrict to those; otherwise commit **every** pending unit found across all three targets.
- Discover pending work per repo with:
  - `git status --porcelain src/leetcode/daily/` (Target A)
  - `git status --porcelain src/leetcode/problems/` (Target D)
  - `git -C courses/dsa-mentorship status --porcelain`
  - `git -C courses/fse13-faang status --porcelain`
- **Never** run `git add -A`. Stage only the exact files of the unit being committed. Leave everything out of scope untouched (other submodules, `build/`, slides, READMEs, etc.).

## Branch handling — do this BEFORE committing each unit (critical)

Each repo must be on the **correct feature branch** for the work. Never commit on `master` / `main` / a default branch.

1. Derive the expected branch from the folder being committed:
   - **Target A (daily):** `phuc-nguyen/daily-lc-challenge`
   - **Target B (dsa lesson `lesson-NN-<topic>`):** `phuc-nguyen/lesson-NN-<topic>` (e.g. `lesson-06-graph/` → `phuc-nguyen/lesson-06-graph`)
   - **Target C (fse13 folder `NN-<topic>`):** `phuc-nguyen/review-NN-<topic>` — but **first prefer an existing local branch matching `phuc-nguyen/review-NN*`** (`git -C courses/fse13-faang branch --list 'phuc-nguyen/review-NN*'`), because topics are sometimes shortened (folder `01-two-pointers-sliding-window` → branch `phuc-nguyen/review-01-two-pointers`). Use the existing match if there's exactly one; if none, create `phuc-nguyen/review-NN-<full-topic>` and flag the name in your summary.
   - **Target D (main-repo `src/leetcode/problems/<topic>/`):** `phuc-nguyen/review-<series>` — a self-defined *review series* that groups several related `problems/<topic>` folders under one branch (e.g. `phuc-nguyen/review-graph-sp-mst` covers `shortest_path/` + MST; `phuc-nguyen/review-two-pointer` covers `two_pointers/`). The folder name does **not** map 1:1 to a branch. Resolve the branch like this:
     1. Determine the problem's **canonical topic** from its `problems/<topic>/` folder (and the code). The full topic vocabulary lives in `scripts/find_unsolved_leetcode.py` → `TOPIC_ALIASES` (e.g. folder `shortest_path` → `shortest-path`, `two_pointers` → `two-pointers`, `dsu` → `union-find`).
     2. **Prefer an existing `phuc-nguyen/review-*` branch whose series covers that topic** (`git branch --list 'phuc-nguyen/review-*'`). Use an existing match when exactly one series fits (e.g. `shortest-path`/`mst` → `review-graph-sp-mst`).
     3. If **no** review branch covers the topic, **create** `phuc-nguyen/review-<series>`, naming `<series>` from the topic slug(s) in the script's `TOPIC_ALIASES` (a short family name is fine, e.g. `review-trie`, `review-segtree`). Flag the created name. Only **ask** the user when it's genuinely ambiguous which existing series the problem belongs to.
     - **The branch is decided by the problem's `problems/<topic>/` folder, NEVER by whichever branch happens to be checked out.** The current branch counts only when it is *independently* the branch the folder resolves to. A new file in `problems/ad_hoc/` while HEAD sits on `phuc-nguyen/review-graph-sp-mst` must be committed on the ad-hoc series branch (creating it if needed) — **not** on `review-graph-sp-mst` just because you were already there. Before staging any Target D unit, re-derive the branch from its folder and compare it against `git rev-parse --abbrev-ref HEAD`; if they differ, check out (or create) the right one first.
     - Units from **different `problems/<topic>` folders that resolve to different series must go on different branches**, each in its own checkout — even when they were all written in the same sitting and show up in one `git status`. Never let convenience batch unrelated topics onto one branch.
     - These review branches often sit **behind `master`** (an already-merged series) — commit the new problem on the branch as-is and note it's behind master; do **not** rebase/rewrite without asking. Exception: the `[problem]` flag authorizes exactly this rebase, as part of the publish flow (see **Push & PR flags**).
2. Check the repo's current branch (`git -C <repo> rev-parse --abbrev-ref HEAD`).
   - Already on the expected branch → proceed.
   - Expected branch exists locally → `git -C <repo> checkout <branch>` (new practice files are untracked and carry over safely).
   - Expected branch does **not** exist → create it. If the scoped changes are **all untracked** (new files), branch off the repo's default branch for a clean topic branch: `git -C <repo> checkout <main|master>` then `git -C <repo> checkout -b <branch>` (untracked files survive the switch). If any scoped file is a **modified tracked** file (so switching base could conflict), instead create the branch off the current HEAD (`git -C <repo> checkout -b <branch>`) and flag it. Report which base was used.
   - If any `checkout` fails (conflict / dirty tree), **stop and report** — do not force anything.
3. When multiple units map to different branches (e.g. two lesson folders), process them **one branch-group at a time**: checkout that branch, commit all its units, then move to the next.

## Commit-message formats

Pick `[add]` for brand-new files (untracked / added), `[update]` for modifications to already-tracked files (derive from the porcelain status code).

**Target A — daily LeetCode** (one commit per date folder; `YYYY_MM_DD` → `DD-MM-YYYY`):
```
[daily] add leetcode daily challenge DD-MM-YYYY (lc <NUMBER> - <technique>)
```

**Target B — dsa-mentorship lesson problem** (`<LETTER>` from the file `A. ….cpp` → `A`):
```
[add][lesson-NN-<topic>] <LETTER>: <technique>
```

**Target B — dsa-mentorship homework** (files under `lesson-NN-<topic>/hw/`; the tag is literally `[homework]` even though the folder is `hw`):
```
[add][lesson-NN-<topic>][homework] <LETTER>: <technique>
```

**Target C — fse13-faang** (keep the style already in that repo's git log — `[add]`/`[update]` + free-text + `(lc …)`):
```
[add] <technique> (lc <NUMBER>)
```
- `<technique>` here is a concise **5-10 word** main-technique phrase (same spirit as the other repos — not a long free-text sentence).
- LC number from the filename's leading 4-digit id (keep zero-padding, e.g. `lc 0076`). If it's a homework-numbered file (`1. ….py`, no LC id), use `(hw <n>)` instead of `(lc …)`.

**Target D — main-repo review problem** (`src/leetcode/problems/<topic>/`):
```
[add][review][<topic>] solve lc <NUMBER> - <technique>
```
- `[update]` (instead of `[add]`) for modifications to already-tracked files.
- `[<topic>]` = the problem's **canonical topic slug** from `scripts/find_unsolved_leetcode.py` → `TOPIC_ALIASES` (e.g. `shortest-path`, `two-pointers`, `union-find`) — **not** the `problems/<topic>/` folder name and **not** the branch/series name.
  - Exception: folder `problems/ad_hoc/` → slug `ad-hoc`, series branch `phuc-nguyen/review-ad-hoc`. This one is deliberately absent from `TOPIC_ALIASES` because that table's values are real LeetCode tag slugs and LeetCode has no tag for "needs no specific technique". Use `ad-hoc` only for problems solved by direct reasoning/implementation with no characteristic algorithm or data structure — never as a dumping ground for problems you have not classified yet (that is what `problems/unknown/` is for).
- `<NUMBER>` = the code's real LC id, **without** zero-padding (e.g. `lc 3604`). No parentheses around it.
- `<technique>` here is a **descriptive** phrase/clause (longer than the other targets — a short sentence is fine), e.g. `Dijkstra with time-windowed edges, arrival = max(t, start)+1`.
- Full example: `[add][review][shortest-path] solve lc 3112 - Dijkstra on undirected graph, skip node v when arrival >= disappear[v]`

`<technique>` = the **core idea**: max **5-6 words** (Targets A/B), **5-10 words** (Target C), or a **descriptive phrase/clause** (Target D).

## How to fill in NUMBER and technique
- **Read the source file(s)** in each unit first. Derive both the problem number and the technique from the **actual code** (the solved function + algorithm), NOT from the filename — filenames are often leftover templates and may not match the code inside.
- If the filename's number disagrees with the code, keep the filename as-is but use the **code's** real number in the message, and note the mismatch in your summary.

## Lint before staging (main repo, REQUIRED)

The main repo has pre-commit configured (`.pre-commit-config.yaml`: clang-format per
`.clang-format`, `g++ -std=c++20 -fsyntax-only`, whitespace/EOF hygiene). CI runs the same hooks
on every PR diff, so an unlinted commit will block auto-merge.

- Before staging each Target A/D unit (after writing the annotation block):
  `pre-commit run --files <unit files>`. Fixer hooks modify files in place and report "failed" on
  the first pass — re-run until clean, then stage the fixed result. Lint fixes are part of the
  unit commit, **never** a separate commit.
- If the syntax check fails on a **missing `#include`** (the LeetCode template compiles there via
  transitive includes that libstdc++ on CI does not provide), add the missing include — that is a
  mechanical portability fix, not a solution change — and note it in the summary. Any **other**
  syntax failure means broken code → the empty/unsolved guardrail applies (flag, don't commit).
- Targets B/C (submodules) have no pre-commit config yet; commit them as-is.
- If `pre-commit` is missing on the machine, install it (`pipx install pre-commit`) instead of
  skipping lint.

## Annotate each solution before committing (REQUIRED)

Before staging any solution file, prepend a block comment at the **top of the file** (right after the
`#include`s / imports, before the `Solution` class) documenting **the problem itself** and the
**reference-optimal** approach. Use `/* … */` for C/C++ and the language's block-comment equivalent
otherwise (`""" … """` for Python). The block must contain, in this order:
- **Title line** — `LC <NUMBER> - <Title>` (or the Codeforces problem id/title for course units), plus
  the source URL.
- **Problem** — the problem statement, **fetched from the source** (see below), restated faithfully:
  what is given, what must be returned, and the **constraints** block.
- **Examples** — the source's worked examples (input / output / explanation), **fetched from the
  source**. Keep 2–3 representative ones — enough to pin down the exact I/O shape and at least one
  edge case; do not paste all of them if the source lists many.
- **Best solution** — the name of the optimal (or near-optimal) algorithm for the problem.
- **Time & Space complexity** of that best solution (Big-O, e.g. `Time: O(V+E)`, `Space: O(V)`), with a
  one-clause justification each.
- **Approach (detail)** — a numbered, step-by-step explanation of *how* the best solution works and
  *why* it is correct (the key insight), detailed enough to reconstruct the solution from the comment.
- **Your solution** — a **verdict sentence** stating plainly whether the algorithm the committed code
  actually runs *is* the best solution documented above. Start it with one of these three verdicts,
  then justify in the same sentence or the next one:
  - `MATCHES BEST` — the code implements the documented optimal algorithm.
  - `SUBOPTIMAL` — the code solves the problem correctly but with worse complexity. State the code's
    own Time/Space, name the gap (e.g. `O(n^2) vs O(n log C)`), and say why it still passes (or does
    not) under the stated constraints.
  - `INCORRECT` — the code does not solve the problem. Name the failing case.

  This section is about **the code in the file**, not the ideal — never write `MATCHES BEST` for a
  file whose live method is not the optimal one. If the file contains both an optimal and a
  suboptimal implementation, judge the one actually wired up (the method the platform calls) and
  name the dead one. Any verdict other than `MATCHES BEST` must also be repeated in the commit
  **summary**.

### Fetching the problem statement + examples (REQUIRED)

The statement and examples must come from the **actual source**, not from memory — use `WebFetch`.
Resolve the source URL per target:
- **Target A (`src/leetcode/daily/`) and Target D (`src/leetcode/problems/`)** — LeetCode:
  `https://leetcode.com/problems/<slug>/`. Derive `<slug>` from the problem title in kebab-case
  (e.g. `3517. Smallest Palindromic Rearrangement I` → `smallest-palindromic-rearrangement-i`).
- **Target B (`courses/dsa-mentorship`)** — Codeforces. These files usually already carry the exact
  URL in a leading `//` comment (e.g. `// https://codeforces.com/group/.../problem/C`) — **use that
  URL**; it is authoritative for the group/contest-scoped statement.
- **Target C (`courses/fse13-faang`)** — LeetCode via the filename's 4-digit id (strip zero-padding
  to build the slug lookup). For homework-numbered files with no LC id, use whatever source URL the
  file references; if there is none, see the fallback below.

Fallback when the fetch fails (offline, 403/404, login-walled, or no resolvable URL): write the
statement and examples from your own knowledge of the problem, mark that section in the file with a
`(statement not verified against source — reconstructed)` note, and **flag the unit in your commit
summary**. Never silently present reconstructed text as sourced.

Rules for the annotation:
- Document the **objectively best** solution for the problem, even when the committed code uses a
  different / less-optimal approach (the user's code may not yet be optimal). When the committed code
  diverges from the documented best, that divergence goes in **both** places: the **Your solution**
  verdict inside the file, and your commit **summary**.
- Identify the problem from the **actual code**, not the filename — then fetch *that* problem's
  statement. If the filename's id points at a different problem than the code solves, the statement
  must match the **code**.
- Keep the statement/examples **concise and verbatim in substance** — trim LeetCode's boilerplate
  ("Return the answer…" preamble, follow-up prompts, tag lists), but never reword the constraints or
  alter an example's numbers.
- The comment is part of the **same unit commit** (included in the `[add]`/`[update]`), never a
  separate commit. If a file was already committed this run without it, `--amend` that commit.
- If you cannot confidently determine the best solution, **ask** rather than guessing.

## Guardrails
- **Do NOT add any `Co-Authored-By` / trailer line.** The user writes all the solution code; commits are authored solely by the user.
- **Never** `git add -A`; stage only the unit's own files.
- If a unit's solution is **empty/unsolved** or the code is broken, do NOT commit it silently — flag it and ask whether to skip, or wait for the user to finish it.
- If a unit is genuinely ambiguous (can't tell the problem/technique from the code), ask rather than guess.
- Committing inside a submodule leaves the **parent repo's submodule pointer** showing as modified — that's expected. Do **not** auto-commit the pointer bump in the parent; leave it for the user.
- Do **not** push. Only push (or force-push) if the user explicitly asks — passing `[lc]` /
  `[problem]` **is** that explicit ask, but only for the matching main-repo branches (see below).
  Submodules are never pushed by this command.

## Push & PR flags — `[lc]` / `[problem]`

When `$ARGUMENTS` contains these flags, publishing happens **after** all local unit commits are
done (local commits always happen regardless):

- `[lc]` → publish **Target A**: `phuc-nguyen/daily-lc-challenge`.
- `[problem]` → publish **Target D**: **every** `phuc-nguyen/review-*` series branch that
  received commits in this run (one PR per branch).
- No flag → local commits only (the default; nothing is pushed).

Publish steps, per branch:
1. Update the base: `git fetch origin`, then fast-forward local `master`
   (`git checkout master && git merge --ff-only origin/master`).
2. `git checkout <branch> && git rebase master`. On any conflict: `git rebase --abort`, report
   that branch as **not published**, and continue with the remaining branches — never resolve
   conflicts or force through.
3. Push: `git push -u origin <branch>` if it has no upstream, else
   `git push --force-with-lease origin <branch>` (history was just rebased).
4. Ensure the opt-in label exists (idempotent):
   `gh label create auto-merge --color 0E8A16 --description "CI merges this PR when lint passes and there are no conflicts" 2>/dev/null || true`
5. PR: if `gh pr list --head <branch> --state open` is empty →
   `gh pr create --base master --head <branch> --fill --label auto-merge`.
   Otherwise the push already updated the open PR — just ensure it carries the label
   (`gh pr edit <number> --add-label auto-merge`).
6. From here CI takes over (`.github/workflows/ci.yml`): the `lint` job re-checks the PR diff and
   the `automerge` job merges the PR once lint is green **and** the PR is conflict-free; a
   conflicting PR gets a bot comment and stays open for the user to merge manually.

## After committing
For each repo you committed in, print its `git log --oneline` for the new commits and the branch it's on, then a combined table of `repo | branch | unit | number | technique`, plus any flagged/skipped units and any branches you created (with their base). When `[lc]`/`[problem]` was passed, also list each published branch's PR URL and whether auto-merge is expected (or why publishing was skipped, e.g. rebase conflict).

Arguments: $ARGUMENTS
