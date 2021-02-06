# Analysis on Web Crawling Algorithms

Course Code- CSE2004 (Data Structures and Algorithms)  
Team Members:  
Prishita Ray  
Navya R G

This project analyses 5 different web crawling algorithms , Depth First Search, Breadth First Search , Page Rank Algorithm (used by Google) , A Star Search (heuristic algorithm) and Adaptive A Star Search in terms of time complexity and memory usage. To improve the efficiency of each of these processes , we also used Cache Control headers to display details of each website like the time when it was last modified , text length , public visibility etc and reduce the time incurred while repeatedly accessing popular sites by loading them from the server again, rather than just invoking the cached loaded version. The implementation has been done using pure C programming. It was concluded that Adaptive A* has a time complexity of O(log n) and requires minimum memory for processing, followed by A* that has a time complexity of O(n). BFS(Breadth First Search) and DFS(Depth First Search) each have an O(n<sup>2</sup>) time complexity which are also have the highest resource consumption. Page Rank was the final algorithm that was analyzed and takes O(kN) time, where k is the number of iterations (we have considered 5 in this project). More details about the results and methodology can be obtained here: https://www.slideshare.net/PrishitaRay/analysis-on-web-crawling-algorithms  

The implementation for BFS, DFS and Page Rank was done by Navya, and those for A*, Adaptive A* and the header files for Cache Control were done by me.  

## Results

Outputs obtained after running the code are attached below: 

### Details of the Root

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa1.JPG">
</p>

### 1. Depth First Search

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa2.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa3.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa4.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa5.JPG">
</p>

### 2. Breadth First Search

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa6.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa7.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa8.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa9.JPG">
</p>

### 3. Page Rank Algorithm

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa10.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa11.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa12.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa13.JPG">
</p>

### 4. A* Search

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa14.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa15.JPG">
</p>

### 5. Adaptive A* Search

<p align="left">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa16.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa17.JPG">
  <img width="500" height="400" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/dsa18.JPG">
</p>

## Analysis

The comparison of these search algorithms in terms of time complexity, memory usage and efficiency can be observed using this 3D bar plot:  
<p align="center">
  <img width="800" src="https://github.com/PRISHIta123/web_crawlers/blob/master/screenshots/SAC.JPG">
</p>
