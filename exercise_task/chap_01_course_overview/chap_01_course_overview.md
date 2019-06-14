
# exercise_task1

## 1. VIO的认知与文献阅读


## 2. 四元素和李代数更新

**代码工程见附件**


**运行结果**
```
the current Pose of R: 
 1 -1  5
 5  4  5
 1  7  9

 the current Pose of q:[x,y,z,w] 
0.258199 0.516398 0.774597  1.93649

 the update Pose of rotate vector 
0.01 0.02 0.03

 the updated_pose_from_rotateMatrix:  R <--- R*exp^(w^hat) 
  0.601751   -0.59689   0.530677
  0.719429   0.693654 -0.0355792
 -0.346869   0.403194   0.846827

 the updated_pose_from_Quaternion: q <--- q*[1, 1/2w]^T 
  0.629893   -0.58363   0.512456
  0.697509   0.715302 -0.0427046
 -0.341637   0.384342   0.857651

```

## 3.李代数求带
$$
 \begin{flushleft}
 使用右乘  \mathfrak{so}(3)
 \end{flushleft}
 $$

$$
\frac{\partial(R^{-1}p)}{\partial{R}}  \tag{1}
$$