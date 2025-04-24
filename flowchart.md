
#flowchart TD

``` mermaid   
flowchart TD
    A[Start] --> B[Input a, b]
    B --> C{Is a > b?}
    C -- Yes --> D[Result = a - b]
    C -- No --> E[Result = b - a]
    D --> F[Print result]
    E --> F
    F --> G[End]

