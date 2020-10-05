# Analysis on Web Crawling Algorithms

Course Code- CSE2004 (Data Structures and Algorithms)  
Team Members:  
Prishita Ray  
Navya R G

This project analyses 5 different web crawling algorithms , Depth First Search, Breadth First Search , Page Rank Algorithm (used by Google) , A Star Search (heuristic algorithm) and Adaptive A Star Search in terms of time complexity and memory usage. To improve the efficiency of each of these processes , we also used Cache Control headers to display details of each website like the time when it was last modified , text length , public visibility etc and reduce the time incurred while repeatedly accessing popular sites by loading them from the server again, rather than just invoking the cached loaded version. The implementation has been done using pure C programming. It was concluded that Adaptive A* has a time complexity of O(log n) and requires minimum memory for processing, followed by A* that has a time complexity of O(n). BFS(Breadth First Search) and DFS(Depth First Search) each have an O(n<sup>2</sup>) time complexity which are also have the highest resource consumption. Page Rank was the final algorithm that was analyzed and takes O(kN) time, where k is the number of iterations (we have considered 5 in this project). More details about the results and methodology can be obtained here: https://www.slideshare.net/PrishitaRay/analysis-on-web-crawling-algorithms  

The implementation for BFS, DFS and Page Rank was done by Navya, and those for A*, Adaptive A* and the header files for Cache Control were done by me.  

Outputs obtained after running the code are attached below:  

<p align="center">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa1.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa2.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa3.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa4.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa5.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa6.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa7.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa8.JPG">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/dsa9.JPG">
</p>

The comparison of these search algorithms in terms of time complexity, memory usage and efficiency can be observed using this 3D bar plot:  
<p align="center">
  <img width="460" height="300" src="https://github.com/PRISHIta123/web_crawlers/blob/master/SAC.JPG">
</p>
