#!/usr/bin/env bash
# pre-commit hook body: syntax-check C++ solution files.
#
# Why this wrapper exists: the solutions are written against GNU libstdc++ (LeetCode /
# Codeforces), and many of them `#include <bits/stdc++.h>` — a GCC-only convenience header.
# CI runs on Ubuntu where that header exists, but Apple clang on macOS does not ship it, so a
# bare `g++ -fsyntax-only` fails locally on 20+ otherwise-valid files. When the header is
# missing we generate a shim into a cache dir and add it to the include path, so local and CI
# agree on what "passes".
set -uo pipefail

CXX=${CXX:-g++}
STD=${CPP_STD:-c++20}

# Some solutions include the repo's own reusable headers by repo-relative path,
# e.g. #include "topics/graph/disjoint_set_union.hpp" — so the repo root is an include root.
repo_root=$(git rev-parse --show-toplevel 2>/dev/null || pwd)
extra_inc=(-I "$repo_root")

if ! printf '#include <bits/stdc++.h>\nint main(){}\n' \
     | "$CXX" -std="$STD" -fsyntax-only -x c++ - >/dev/null 2>&1; then
    shim_root="${TMPDIR:-/tmp}/dsa-journey-cpp-shim"
    shim="$shim_root/bits/stdc++.h"
    if [ ! -f "$shim" ]; then
        mkdir -p "$shim_root/bits"
        cat > "$shim" <<'HEADER'
// Generated shim for macOS/libc++, which does not ship GCC's <bits/stdc++.h>.
// Covers the standard library surface the solutions in this repo actually use.
#pragma once
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
HEADER
    fi
    extra_inc+=(-I "$shim_root")
fi

status=0
for f in "$@"; do
    if ! "$CXX" -std="$STD" -fsyntax-only "${extra_inc[@]+"${extra_inc[@]}"}" "$f"; then
        status=1
    fi
done
exit "$status"
