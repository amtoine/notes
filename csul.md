# nushell/nushell: `with-env` output PR

Related to #8119.
Should address the review comment by @sholderbach from #8119.


# Description

this PR adds the output to the new example for the `with-env` command introduced by #8119.

```bash
with-env {X: "Y", W: "Z"} { [$env.X $env.W] }
```
should output
```bash
["Y", "Z"]
```
hence the proposition from @sholderbach, i.e.
```rust
Some(Value::list(
    vec![Value::test_string("Y"), Value::test_string("Z")],
    Span::test_data(),
))
```

# User-Facing Changes
_none_

# Tests + Formatting

not really a test, only the output value for the last `with-env` example

- :heavy_check_mark: `cargo fmt --all`
- :heavy_check_mark: `cargo clippy --workspace -- -D warnings -D clippy::unwrap_used -A clippy::needless_collect`
- :heavy_check_mark: `cargo test --workspace`

# After Submitting
_none_

