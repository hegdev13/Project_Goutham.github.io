# Business Use Case
###### Vishruth G H


## Food Production and Distribution
A sustainable city relies heavily on efficient food production, management, and distribution systems. The region's fertile soil is well-suited for cultivating crops such as groundnuts, jowar, and rice. These crops not only fulfil the city's food requirements but also create significant trade opportunities due to their high demand.
Goutham's strategic location provides access to regional and national markets, enhancing trade and diversifying resources. Trade also helps establish connections between farmers and merchants, which can help optimise the sector for better profitability and sustained growth.
Efficient food distribution systems ensure that locally sourced vegetables and grains are delivered to restaurants, marketplaces, shelters, camps, and educational institutes across the city. This not only promotes food security and well-being but also minimizes the environmental footprint by reducing transportation costs and emissions. Supporting local agriculture strengthens the community while reinforcing Goutham’s commitment to sustainability and economic resilience.

Let's decompose this into smaller use cases and work each one out.

### 1. Rain Prediction for Disaster Prevention
> Task: Weather forecast

> SDG: 11

> Target: 11.5

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


### 2. Dictionary for Crops and Seeds
> Task: Create a dictionary to assist farmers and municipal corporations to keep a record of seeds and crops

> SDG: 11

> Target: 11.a

> Indicator: 11.a.1

Creating a dictionary would assist the farmers and the municipality in establishing good ties with urban, peri-urban and rural areas. This dictionary should just show if there is availability of a certain seed or a crop. If it is not present, then it implies that the produce can not be obtained on the land.
A **trie** data structure would help create this dictionary as it has fast retrieval. It works on the principle of **Space-Time Tradeoff** as it takes a lot of space and executes queries in constant time.

Code for trie on GitHub: [trie implementation](https://github.com/hegdev13/Project_Goutham.github.io/tree/90e0e4f83b8b7d97c2a7b06a8a1bd03e1a2745f1/VGH_Codes)


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
