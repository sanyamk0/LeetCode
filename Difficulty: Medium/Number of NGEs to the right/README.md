<h2><a href="https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right">Number of NGEs to the right</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of <strong>N</strong> integers and <strong>Q</strong> queries of indices. Return a list NGEs[] where NGEs[i] stores the count of elements strictly greater than the current element (arr[indices[i]]) to the right of indices[i].</span></p>
<p><span style="font-size: 18px;"><br><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong> arr[]     = [3, 4, 2, 7, 5, 8, 10, 6</span><span style="font-size: 18px;">]
        queries = 2
&nbsp;       indices[] = [0, 5]
<strong>Output: </strong> 6, 1
<strong>Explanation: </strong>The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.
</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong> arr[]     = [1, 2, 3, 4, 1</span><span style="font-size: 18px;">]
        queries = 2
&nbsp;       indices[] = [0, 3]
<strong>Output: </strong> 3, 0
<strong>Explanation: </strong>The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the </span><span style="font-size: 14pt;">count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N * queries).<br><strong>Expected Auxiliary Space:</strong> O(queries).</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>4</sup></span><br><span style="font-size: 18px;">1 &lt;= arr[i] &lt;= 10</span><sup>5</sup><br><span style="font-size: 18px;">1 &lt;= queries &lt;= 100</span></p>
<p><span style="font-size: 18px;">0 &lt;= indices[i] &lt;= N - 1</span></p>
<p>&nbsp;</p></div>