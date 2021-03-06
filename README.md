# Gradle C++ Transitive Dependency Test App
## Structure
cpp-application "app" module depends on static library "static_one" and static library "static_two" modules.
static library "static_one" module currently depends on "static_two" module.
A needs B needs C. A also directly needs C. 

## Current State
Application "A" does not list static library dependency "C" but still compiles because static library dependency "B" is pulling it in.
If static library dependency "B" switched implementations to not need "C" and removed its dependency from "C", it would break downstream consumer application "A".

```
> Task :app:linkDebug FAILED
/.../app.o: In function `main':
/.../app.cpp:9: undefined reference to `FancyPrint(char const*)'
```

### How to break current state
- Remove "static_two" as a dependency from project "static_one"'s build.gradle.
- Remove references to "static_two" from project "static_one"'s src/main/cpp/impl.cpp (comment out header & function)
- Rebuild and "app" will fail as it needs "static_two".
