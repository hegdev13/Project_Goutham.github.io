# Business Use Case
###### Vishruth G H


## Food Production and Distribution
A sustainable city relies heavily on efficient food production, management, and distribution systems. The region's fertile soil is well-suited for cultivating crops such as groundnuts, jowar, and rice. These crops not only fulfil the city's food requirements but also create significant trade opportunities due to their high demand.
Goutham's strategic location provides access to regional and national markets, enhancing trade and diversifying resources. Trade also helps establish connections between farmers and merchants, which can help optimise the sector for better profitability and sustained growth.
Efficient food distribution systems ensure that locally sourced vegetables and grains are delivered to restaurants, marketplaces, shelters, camps, and educational institutes across the city. This not only promotes food security and well-being but also minimizes the environmental footprint by reducing transportation costs and emissions. Supporting local agriculture strengthens the community while reinforcing Goutham’s commitment to sustainability and economic resilience.

Let's decompose this into smaller use cases and work each one out.

### 1. **Rain Prediction for Disaster Prevention**
> Task: Weather forecast
> 
> SDG: 11
> 
> Target: 11.5
> 
> Indicator: 11.5.1, 11.5.2, 11.5.3(a), 11.5.3(b)

The crops grown in this region, like groundnuts, wheat, tomatoes, potatoes, citrus fruits, and leafy vegetables, require a lot of water and can be easily damaged by heavy rainfall during harvest time. If farmers are informed about expected heavy rains, they can take precautions to protect their crops.

Thanks to the strong technological presence and stronger inter-city relations, Goutham collects data from sensors placed throughout the city and neighbouring areas. These sensors track important factors like wind speed, air quality, humidity, and sunlight, which are stored in a dataset. By analyzing this data, patterns of high humidity and wind can indicate the possibility of rain. Finding these patterns and their frequency can help the farmers predict rains and help them make adjustments accordingly. 

Sample text: LWHHB HWHHD HWHHB HWLHD 
Sample Pattern: HWHHD
explanation: every 5 letters describe the weather at a particular hour. The first 2 letters are about wind speed: LW = Low windspeed, the next 2 are about humidity: HH = High HUmidity, the last letter is about amount of sunlight, B: Bright.
HWHHD indicates rain, hence our pattern will be the code for rain.

The weather prediction system can also pick up other patterns such as sunlight and is versatile in its working. since the dataset is huge, the **Boyer-Moore** sub-string search algorithm will work well. It has a worst-case **efficiency of O(m+n)**. and works on the principles of **Sliding Window**, **Pruning**, and **Prefix and Suffix**.
(The below implementation of Boyer-Moore is modified to find frequency)

Code for Boyer-Moore on GitHub: [Boyer-Moore implementation](https://github.com/hegdev13/Project_Goutham.github.io/blob/54386e1cc178a690b773535bad5353611106cefe/VGH_Codes/Boyer-moore.cpp)



### 2. **Dictionary for Crops and Seeds**
> Task: Create a dictionary to assist farmers and municipal corporations to keep a record of seeds and crops
>
> SDG: 11
>
> Target: 11.a
>
> Indicator: 11.a.1

Creating a dictionary would assist the farmers and the municipality in establishing good ties with urban, peri-urban and rural areas. This dictionary should just show if there is availability of a certain seed or a crop. If it is not present, then it implies that the produce can not be obtained on the land.
A **trie** data structure would help create this dictionary as it has fast retrieval. It works on the principle of **Space-Time Tradeoff** as it takes a lot of space and executes queries in constant time.

Code for trie on GitHub: [trie implementation](https://github.com/hegdev13/Project_Goutham.github.io/tree/90e0e4f83b8b7d97c2a7b06a8a1bd03e1a2745f1/VGH_Codes)



### 3. **Storing expiry dates of a batch of produce**
> Task: Create a way to store expiry date of a batch so that priority can be given to them, and waste can be reduced
>
> SDG: 11
>
> Target: 11.6
>
> Indicator: 11.6.1

As each new batch is stored inside a warehouse or any other storing facility, priority should be given to each batch based on its expiry date to reduce food wastage.

This can be achieved by using a **Binary Search Tree** that can dynamically allocate the **hierarchical data**. Due to the design of the BST, this is easy to manipulate and  it is the natural data structure to store it in.

Code for BST on GitHub: [Binary Search Tree](https://github.com/hegdev13/Project_Goutham.github.io/blob/6551be55daede6453f24f0f0e1de8ffc62c24cfd/VGH_Codes/BinarySearchTree.cpp)


### 4. **Sorting the Produce **
> Task: Sort the produce or rather classify the produce according to size and quality to make tiers to sell at the market
>
> SDG: 11
>
> Target: 11.a
>
> Indicator: 11.a.1

Classifying the produce according to quality/volume allows for better economic growth and better trade as lower tiers are more affordable. This increases trade between urban, peri-urban and rural areas.
The problem of sorting in this condition is a peculiar one as sorting treats each element individually and is not good at classifying. however one particular sorting algorithm, **Quick sort** can be used to classify as the entire data set gets partitioned about a pivot element, hence putting them into piles of better and/or worse separately. Even if the sorting operation is stopped abruptly, the results can still be used to segregate the data into tiers as each pass, in this case, gets us closer to our solution.
Quick sort has a **worst-case efficiency of O(n log n)**, and works on the principle of **Divide-and-Conquer**.

Code for Quicksort on GitHub: [Quick-sort](https://github.com/hegdev13/Project_Goutham.github.io/blob/381475de9b645ba78b1d18ef816b62ab2933fee6/VGH_Codes/quick_sort.cpp)


### 5. **Market price fluctuations**
> Task: Track market prices of produce
> 
> SDG: 11
> 
> Target: 11.a
> 
> Indicator: 11.a.1

Some Food grains and produce fluctuate in the national market at a very high frequency, which reflects the demand and supply of produce. It also helps determine the value of a product for the day/event.  This increases trade between urban, peri-urban and rural areas.
For such frequent updation and manipulations, **Fenwick trees** are efficient to implement on huge data sets and are also faster as they work on bit manipulations. Fenwick trees work on the principle of **bit manipulation**. They have a **worst case efficiency of O(log n)**.

Code for Fenwick trees on GitHub: [Fenwick trees](https://github.com/hegdev13/Project_Goutham.github.io/blob/e2ee0ecc167c823286198e049896eedd06784ca0/VGH_Codes/Fenwick-tree.cpp)


### 6. **Optimal Storage**
> Task: make warehouses at optimal locations around the city.
> 
> SDG: 11
> 
> Target: 11.5
> 
> Indicator: 11.5.1

After production, the produce must be stored at optimal locations around the city for quick relief if disaster strikes. The optimal placement of warehouses also reduces the cost of transport. This problem can easily be figured out using Kruskal's algorithm. 
consider regions around the city as nodes and the distance between possible locations of warehouses as edges(the cost of the edges can be altered according to need), then the minimum spanning tree will give the optimal location for the warehouses.

principle: **Greedy technique**

efficiency: O(E log|v|), efficiency of kruskals is dominated by the sorting algorithm, here we use quicksort.

Code for Kruskal trees on GitHub: [kruskal](https://github.com/hegdev13/Project_Goutham.github.io/blob/8916422652c516fb0eab4504ba348b15ab5e1627/VGH_Codes/Kruskals.cpp)


### 7. **Mapping Products to Storage Locations**
> Task: Map products to warehouses
> 
> SDG: 11
> 
> Target: 11.a
> 
> Indicator: 11.a.1

Inventory is very important to maintain as even striking deals with neighbouring cities require this data. Fast retrievals can be achieved using **hashing**.

principle: **space-time trade off**

efficiency: O(1)

Code for  on GitHub:

### 8. **Minimize the cost to distribute to warehouses**
> Task: Minimize the cost of distributing to multiple warehouses from multiple production areas
> 
> SDG: 11
> 
> Target: 11.a
> 
> Indicator: 11.a.1

From multiple production areas to multiple warehouses and from multiple warehouses to marketplaces, schools, restaurants, and other places of food consumption, an all pair shortest path algorithm can give us the minimum cost that can be achieved. **Floyd's algorithm
** is the best for this implementation. Floyd's works with a **worst case efficiency of O(n³)**

principle: **Kleene's Closure, Dynamic Programming**

efficiency: O(n³)

Code for  on GitHub:

### 9. **Food Inspection**
> Task: To find the shortest (minimum cost) path for the inspector to visit all
> 
> SDG: 11
> 
> Target: 11.5
> 
> Indicator: 11.5.1, 11.5.3(b)

The Food inspectors leave the municipal corporation to all the food storage and distribution areas, to achieve this they need a single source shortest path, hence **Dijkstra's algorithm** can be used. Dijkstra's Algorithm's efficiency is dominated by the data structured used for the priority queue, and a practical lowest upper bound of **O(E log|V|)** can be achieved currently by implementing a **heap**. A Fibonacci heap is said to be able to bring this bound even lower however, there is no right tool available to implement it.

principle: **Greedy Technique**

efficiency: O(E log|v|)

Code for  on GitHub:


### 10. **Food batches need to be called back**
> Task: 
> 
> SDG: 11
> 
> Target: 11.5
> 
> Indicator: 11.5.1, 11.5.3(b)

If a certain batch of food is found to be bad, the manufacture or the food inspector will call it back. and the food batch number has to be searched in a data set, and this has to happen quickly. For this implementation **Rabin-Karp** can be used as it is an optimization on the brute force string search and uses the technique and principles of **hashing**. 

principle: **Space and Time trade off**

efficiency: worst case - O(mn), otherwise - O(m+n)

Code for  on GitHub:


<hr>
# Some other business use cases identified: 
### 1. Bus Scheduling:
Frequent bus scheduling - The city of Goutham, although well connected by multiple modes of transport, heavily depends on its public bus services. Infrequent and poorly scheduled bus services would lead to overcrowding and an unsatisfied user base. A good design for such a system is required.

### 2. Mining: 
Deposits of Mica, Graphite and Quartz mineral ores have been identified near the city's outskirts (close to Damod). These ores can be mined and transported to Goutham's industrial area for further processing using the robust railway, creating a valuable supply chain for industrial use.

### 3. City cleaning Maintenance
City cleaning, maintenance, proper garbage disposal, and efficiently segregating recyclable, non-recyclable, biodegradable, and other kinds of waste. A clean city invites more people, which increases the commercial activities of the city. 


### 4. Medical health camp
health checkups at lower prices for specific regions. Hospitals need to coordinate and circulate this responsibility, covering the entire city. 
