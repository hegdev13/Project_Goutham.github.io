# Business Use Case
###### Vishruth G H


## Food Production and Distribution
A sustainable city relies heavily on efficient food production, management, and distribution systems. The region's fertile soil is well-suited for cultivating crops such as groundnuts, jowar, and rice. These crops not only fulfil the city's food requirements but also create significant trade opportunities due to their high demand.
Goutham's strategic location provides access to regional and national markets, enhancing trade and diversifying resources. Trade also helps establish connections between farmers and merchants, which can help optimise the sector for better profitability and sustained growth.
Efficient food distribution systems ensure that locally sourced vegetables and grains are delivered to restaurants, marketplaces, shelters, camps, and educational institutes across the city. This not only promotes food security and well-being but also minimizes the environmental footprint by reducing transportation costs and emissions. Supporting local agriculture strengthens the community while reinforcing Goutham’s commitment to sustainability and economic resilience.

This system aligns with the following Sustainable Development Goals (SDGs):


### SDG 2. End hunger, achieve food security and improved nutrition and promote sustainable agriculture
> #### SDG Target 2.1
> By 2030, end hunger and ensure access by all people, in particular the poor and people in vulnerable situations, including infants, to safe, nutritious and sufficient food all year round
> - Indicators
>     - 2.1.1 Prevalence of undernourishment
>     - 2.1.2 Prevalence of moderate or severe food insecurity in the population, based on the Food Insecurity Experience Scale (FIES) 

> #### SDG Target 2.3
> By 2030, double the agricultural productivity and incomes of small-scale food producers, in particular women, indigenous peoples, family farmers, pastoralists and fishers, including through secure and equal access to land, other productive resources and inputs, knowledge, financial services, markets and opportunities for value addition and non-farm employment
> - Indicators
>     - 2.3.1 Volume of production per labour unit by classes of farming/pastoral/forestry enterprise size
>     - 2.3.2 Average income of small-scale food producers, by sex and indigenous status

### SDG 12. Ensure sustainable consumption and production patterns

> #### SDG Target 12.3
> By 2030, halve per capita global food waste at the retail and consumer levels and reduce food losses along production and supply chains, including post-harvest losses
> - Indicators
>     - (a) Food loss index and (b) food waste index


To implement such a system we would face some design problems: 
1. For efficient food distribution across the city, we need to map the food sources and destination centres so that the cost function is minimum
- This can be tackled by using a weighted graph to represent the sources and destinations as nodes and the edges as paths to them.
- A minimum spanning tree would help construct the optimal route and hence **Kruskal's** or **Prim's** algorithms can be used

2. Need for a dynamic system with real-time prioritization.
- Having a sorting function that can sort the food supplies of each destination would help reevaluate the weights and reconstruct the spanning tree. **Quick sort** algorithm would be beneficial in this case.



# Some other business use cases identified: 
### 1. Bus Scheduling:
Frequent bus scheduling - The city of Goutham, although well connected by multiple modes of transport, heavily depends on its public bus services. Infrequent and poorly scheduled bus services would lead to overcrowding and an unsatisfied user base. A good design for such a system is required.

### 2. Mining: 
Deposits of Mica, Graphite and Quartz mineral ores have been identified near the city's outskirts (close to Damod). These ores can be mined and transported to Goutham's industrial area for further processing using the robust railway, creating a valuable supply chain for industrial use.

### 3. City cleaning Maintenance
City cleaning, maintenance, proper garbage disposal, and efficiently segregating recyclable, non-recyclable, biodegradable, and other kinds of waste. A clean city invites more people, which increases the commercial activities of the city. 


### 4. Medical health camp
health checkups at lower prices for specific regions. Hospitals need to coordinate and circulate this responsibility, covering the entire city. 
