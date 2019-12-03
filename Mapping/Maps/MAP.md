# Proprietary .map Filetype Guide.

## NOTE: There Are Currently **Two** Types Of Maps
### **-> Node-Vertex (NV)**
### **-> Matrix (MTX)**





---
# Node-Vertex Type

## Example File (example_nv.map)
```
NV
4
5
A
B
C
D
one A B 10
two A C 10
three B C 10
four B D 10
five B D 10
A D
Simple Example Map
```

---
## Lets Break It Down
---

## File Information / Headers
| Line Number  | Value   | Use             |
| ------------ | ------- | --------------- |
| 1            | string  | Map Type (NV)   |
| 2            | integer | # of nodes      |
| 3            | integer | # of verticies  |
> ### IMPORTANT NOTE: This may be expanded as we go along, if we need more variables!

This is usually used with metadata and struct casting, but thats dangerous and annoying to implement. Instead, we are going for a Competition-style input file.

## Payload
| Section  | Data      | Usage / Formatting                                   |
| -------- | --------- | ---------------------------------------------------- |
| 1        | Nodes     | \<NodeName\>                                         |
| 2        | Verticies | \<VertName\> \<VertFrom\> \<VertTo\> \<VertWeight\>  |

> ### IMPORTANT NOTE: NodeName and VertName Has Max Characters Of 128

## Extra Stored Data
| Line Number  | Data                          | Usage / Formatting         |
| ------------ | ----------------------------- | -------------------------- |
| 1            | Default First And Last Nodes* | \<FirstNode\> \<LastNode\> |
| 2            | Map Description               | String(Max 1024 Chars)     |

* If No Default First / Last Node, set 0.

---
## Recap
---

```
--------------------------
NV                        |
4                         | File Information / Headers
5                         |
--------------------------
A                         |
B                         | 
C                         |
D                         |
one A B 10                | Payload
two A C 10                |
three B C 10              | 
four B D 10               |
five B D 10               |
--------------------------
A D                       | Extra Stored Data  
Simple Example Map        |  
```





---
# Matrix Type

> TODO: Dont touch this, Im working on this right now!