# dsa-journey — working rules

This repo is a personal DSA study journal (main repo `dsa-journey` + two git submodules:
`courses/dsa-mentorship`, `courses/fse13-faang`). The rules below are authoritative and live
**in this repo** (not machine-local memory) so they apply on every machine.

## Git workflow (STRICT)

1. **DSA C++ solution code is always committed on its own topic branch — never directly on the
   base branch** (`master` in the main repo, `main` in the submodules). Organize by topic; solution
   code reaches the base branch only via a **merged PR** (the user merges PRs themselves).
   Branch naming:
   - daily LeetCode (main repo `src/leetcode/daily/`) → `phuc-nguyen/daily-lc-challenge`
   - dsa-mentorship lesson `lesson-NN-<topic>` → `phuc-nguyen/lesson-NN-<topic>`
   - fse13-faang review `NN-<topic>` → `phuc-nguyen/review-NN-<topic>` (prefer an existing
     `phuc-nguyen/review-NN*` match; topics are sometimes shortened)
   - main-repo review series (`src/leetcode/problems/<topic>/`) → `phuc-nguyen/review-<series>`, a
     self-defined series grouping several related `problems/<topic>` folders under one branch
     (e.g. `review-graph-sp-mst` covers `shortest_path/` + MST). Folder does not map 1:1 to a
     branch — prefer an existing `phuc-nguyen/review-*` that fits the topic's algorithm family; if
     none exists, create `phuc-nguyen/review-<series>` named from the canonical topic vocabulary in
     `scripts/find_unsolved_leetcode.py` (`TOPIC_ALIASES`). Ask only when it's genuinely ambiguous.

2. **Only "overall" / non-solution files may be committed directly on the base branch**: this
   `CLAUDE.md` and other Claude config, `README`, tooling/scripts. Everything that is DSA solution
   code goes on a topic branch (rule 1).

   For anything under `.claude/` this is a **standing instruction, not a per-time confirmation** —
   commit it straight onto the base branch (`master`), then **rebase every active topic branch onto
   the updated base** so no branch carries a stale copy of the rules. Push the base and force-push
   (`--force-with-lease`) the rebased topic branches. `README`/tooling changes still follow the
   old "ask first" behaviour.

3. **Before creating a topic branch off the base branch, ensure the local base is up to date with
   its remote first** — `git fetch`, then fast-forward the base (`git merge --ff-only origin/<base>`).
   Always branch from an up-to-date base so the topic branch and its future PR stay clean. This
   applies to the main repo (`master`) and to each submodule (`main`).

4. Submodules are independent repos — commit inside them with `git -C courses/<name> …` on their
   own topic branches. Committing in a submodule leaves the parent repo's submodule pointer showing
   as modified; **leave that pointer bump for the user** (do not auto-commit it).

5. **Never push or merge to the base branch without an explicit request.** The user merges all PRs.

See `.claude/commands/commit-progress.md` for the full per-repo commit-message formats and unit rules.
