PROBLEM
======
There is a large storage for storing tomatoes at Chulsoo's tomato farm. Tomatoes are placed one by one into the compartments of grid-shaped boxes, as shown in the image below. Then, the boxes are stacked vertically and stored in the warehouse.

<img src="img1.png">

Among the tomatoes stored in the warehouse, some are well-ripened, while others may still be unriped. After one day of storage, ripe tomatoes affect the adjacent unripe tomatoes, causing them to ripen. An adjacent tomato refers to the tomatoes located in six directions: up, down, left, right, front, and back. Tomatoes located diagonally are not affected, and it is assumed that a tomato cannot ripen on its own. Chulsoo wants to know the minimum number of days required for all the tomatoes stored in the warehouse to ripen. Write a program to calculate the minimum number of days required fore all tomatoes to ripen, given the size of the gred-shaped boxes in the wraehouse and the information about ripe and unripe tomatoes. However, some compartments in the box might not contain tomatoes.


INPUT
======
In the first line, we are given two integers M, N representing the size of the boxes and H representing the number of boxes stack. M represents the number of horizontal cells in the box and N represents the number of vertical cells in the box. However, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, and 1 ≤ H ≤ 100. Starting from the second line, information about the tomatoes stored from the bottommost box to the topmost box is provided. From the second line to the Nth line represents the information for one box. Each line represents the status of tomatoes in a horizontal row within the box, given as M integers. An integer 1 represents a ripe tomato, 0 represents an unripe tomato and -1 represents an empty cell with no tomato. These N lines are repeated H times.

The input will only be provided if there is at least one tomato.


OUTPUT
======
You should calculate and output the minimum number of days required for all the tomatoes to ripen. Print 0 if all the tomatoes are already ripe when stored, and print -1 if it is impossible for all tomatoes to ripen.


SOURCE LINK
======
https://www.acmicpc.net/problem/7569
