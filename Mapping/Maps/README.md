# Proprietary .map Filetype Guide. 
### (Version 3)

## NOTE: There Are Currently **Two** Types Of Maps
### [**-> Node-Vertex (NV)**](#anchorNV)
### [**-> Matrix (MATRIX)**](#anchorMATRIX)





---
# <a name="anchorNV"></a>Node-Vertex Type

## Example File (example_nv.map)
```
v3
NV
F
4
6
A
B
C
D
one A B 10
two A C 10
three B C 10
four C B 10
five B D 10
six C D 10
A D
SP
Simple Example Node-Vertex Map
```

---
## Lets Break It Down
---

## File Information / Headers
| Line Number  | Value   | Use               |
| ------------ | ------- | ----------------- |
| 1            | string  | Version           |
| 2            | string  | Map Type (NV)     |
| 3            | list    | Flags (See Below) |
| 4            | integer | # of nodes        |
| 5            | integer | # of verticies    |
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
| 2            | Recommended Algorithm         | Flag (See Below)           |
| 3            | Map Description               | String(Max 1024 Chars)     |

* If No Default First / Last Node, Set Respective Value To 0.

---
## Recap
---

```
--------------------------
v3                        |
NV                        |
F                         | File Information / Headers
4                         | 
6                         |
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
six C D 10                |
--------------------------
A D                       |
SP                        | Extra Stored Data  
Simple Example Map        |  
--------------------------
```





---
# <a name="anchorMATRIX"></a>Matrix Type

## Example File (example_matrix.map)
```
v3
MATRIX
F
4
6
1
A
B
C
D
0 10 10 0
0 0 10 10
0 10 0 10
0 0 0 0
0 1 1 0
0 0 1 1
0 1 0 1
0 0 0 0
0 one two 0
0 0 three five
0 four 0 six
0 0 0 0
A D
SP
Simple Example Matrix Map
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
| 1            | string  | Version             |
| 2            | string  | Map Type (MATRIX)   |
| 3            | list    | Flags (See Below)   |
| 4            | integer | # of nodes          |
| 5            | integer | # of verticies      |
| 6            | boolean | Enable Vert Name    |
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
| 2            | Recommended Algorithm         | Flag (See Below)           |
| 3            | Map Description               | String(Max 1024 Chars)     |

> *If No Default First / Last Node, set 0.

---
## Recap
---

```
--------------------------
v3                        |
MATRIX                    |
F                         | File Information / Headers
4                         |
6                         |
1                         |
--------------------------
A                         |
B                   Nodes |
C                         |
D_________________________|
0 10 10 0                 |
0 0 10 10          Weight |
0 10 0 10                 |
0_0_0_0___________________| Payload
0 1 1 0                   |
0 0 1 1      Connectivity |
0 1 0 1                   |
0_0_0_0___________________|
0 one two 0               |
0 0 three five     Vertex |
0 four 0 six         Name |
0 0 0 0                   |
--------------------------
A D                       |
SP                        | Extra Stored Data  
Simple Example Matrix Map |
--------------------------
```

---
# <a name="anchorEXTRA"></a>Extra Information!

## Map Flags
A List Containing A Variety Of "Flags" That Can Help Describe The Limitations Of The Graph
> **NOTE**: All Flags Are Single Lettered And Seperated By Spaces!

| Flag Letter | Meaning                                                           |
| ----------- | ----------------------------------------------------------------- |
| F           | Mandatory Flag For All Map Files (Used To Help With Data Padding) |
| N           | Contains Negative Cycles / Negative Weights                       |
| S           | Contains Self-Loops (A Node That Has A Vertex To Itself)          |
| W           | Does Not Contain Different Weight Values (All Values Same)        |
| A           | Auto Generated                                                    |
| X           | Large (Contains More Than 64 Nodes)                               |

## Recommended Algorithm
The Type Of Algorithm The Map Was Designed For.

| Key  | Algorithm Type           |
| ---- | ------------------------ |
| SP   | Shortest Path            |
| MST  | Minimum Spanning Tree    |
| APSP | All Pairs Shortest Path  |
| FLOW | Minimum Flow             |
