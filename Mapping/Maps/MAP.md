# Proprietary .map Filetype Guide.

## Example File (map1.map)
```
4
5
A 1 2
B 2
C 3
D 4
one A B 10
two A C 10
three B C 10
four B D 10
five B D 10
Simple Example Map
```

---
## Lets Break It Down
---

## File Information / Headers
| Line Number  | Value   | Use             |
| ------------ | ------- | --------------- |
| 1            | integer | # of nodes      |
| 2            | integer | # of verticies  |
> ### IMPORTANT NOTE: This may be expanded as we go along, if we need more variables!

This is usually used with metadata and struct casting, but thats dangerous and annoying to implement. Instead, we are going for a Competition-style file.

## Payload
| Section  | Data      | Usage / Formatting                                   |
| -------- | --------- | ---------------------------------------------------- |
| 1        | Nodes     | \<NodeName\> \<NodeId\> \<Distance*\>                |
| 2        | Verticies | \<VertName\> \<VertFrom\> \<VertTo\> \<VertWeight\>  |

> ### IMPORTANT NOTE: NodeName and VertName Has Max Characters Of 128

\* If First Node, set 0. Else, set blank

## Extra Stored Data
| Line Number  | Data            | Usage / Formatting     |
| ------------ | --------------- | ---------------------- |
| 1            | Map Description | String(Max 1024 Chars) |


---
## Recap
---

```
--------------------------
4                         | File Information / Headers
5                         |
--------------------------
A 1 2                     |
B 2                       | 
C 3                       |
D 4                       |
one A B 10                | Payload
two A C 10                |
three B C 10              | 
four B D 10               |
five B D 10               |
--------------------------
Simple Example Map        | Extra Stored Data   
```