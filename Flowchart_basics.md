#flowchart basics practice     
```mermaid   
%%{init: {"flowchart": {"htmlLabels": false}} }%%
flowchart TB
    markdown["`This **is** _Markdown_`"]
    newLines["`Line1
    Line 2
    Line 3`"]
    markdown --> newLines
    markdown --> B(comming to next line)
    B --> C([shape for start and stop])
    B --> D[(shape fot database)]
    C & D --> E((shape for start))
    newLines --> E
    E --> G> this line for direction]
    G --> Z(((stop)))
