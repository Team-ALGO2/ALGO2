# Proprietary .map Filetype Guide.

## NOTE: There Are Currently **Two** Types Of Maps
### [**-> Node-Vertex (NV)**](#anchorNV)
### [**-> Matrix (MATRIX)**](#anchorMATRIX)





---
# <a name="anchorNV"></a>Node-Vertex Type

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
five C D 10
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

> ### IMPORTANT NOTICES: 
> #### NodeName and VertName Has Max Characters Of 128
> #### NodeName and VertName Cannot Be `0` (Reserved Character)

## Extra Stored Data
| Line Number  | Data                          | Usage / Formatting         |
| ------------ | ----------------------------- | -------------------------- |
| 1            | Default First And Last Nodes* | \<FirstNode\> \<LastNode\> |
| 2            | Map Description               | String(Max 1024 Chars)     |

* If No Default First / Last Node, Set Respective Value To 0.

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
--------------------------
```





---
# <a name="anchorMATRIX"></a>Matrix Type

## Example File (example_matrix.map)
```
MATRIX
4
5
1
A
B
C
D
0 10 10 0
0 0 10 10
0 0 0 10
0 0 0 0
0 1 1 0
0 0 1 1
0 0 0 1
0 0 0 0
0 one two 0
0 0 three four
0 0 0 five
0 0 0 0
A D
Simple Example Map
```

---
## Lets Break It Down
---

## Matrix Structure
x-axis -> Node To  
y-axis: -> Node From

```
           Node To
            |---|
         == X X X
Node From | X X X
         == X X X
```

Matrix Grid Is (# of Nodes) X (# of Nodes)
AKA: (NxN)

## File Information / Headers
| Line Number  | Value   | Use                 |
| ------------ | ------- | ------------------- |
| 1            | string  | Map Type (MATRIX)   |
| 2            | integer | # of nodes          |
| 3            | integer | # of verticies      |
| 4            | boolean | Enable Vert Name    |
> ### IMPORTANT NOTE: This may be expanded as we go along, if we need more variables!

This is usually used with metadata and struct casting, but thats dangerous and annoying to implement. Instead, we are going for a Competition-style input file.

## Payload
| Section  | Data         | Types                        | Formatting                                                   |
| -------- | ------------ | ---------------------------- | ------------------------------------------------------------ |
| 1        | Weight       | \<WeightMatrix\> (NxN)       | Any Value From 2147483647 To -2147483647 (i +- From Min/Max) |
| 2        | Connectivity | \<ConnectivityMatrix\> (NxN) | 1 If Connected, 0 If Not.                                    |
| 3        | Vertex Name  | \<VertexNametMatrix\>* (NxN) | VertName, 0 If No Name (Use Default Value)                   |

> ### IMPORTANT NOTICES: 
> #### NodeName and VertName Has Max Characters Of 128
> #### NodeName and VertName Cannot Be `0` (Reserved Character)
> #### If Vert Name Is Disabled, **DO NOT FILL IN SECTION 3**

## Extra Stored Data
| Line Number  | Data                          | Usage / Formatting         |
| ------------ | ----------------------------- | -------------------------- |
| 1            | Default First And Last Nodes* | \<FirstNode\> \<LastNode\> |
| 2            | Map Description               | String(Max 1024 Chars)     |

> *If No Default First / Last Node, set 0.