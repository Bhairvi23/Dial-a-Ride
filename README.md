# Dial-a-Ride
A typical passenger request in Dial a ride problem will look like,
<Clock tower, Graphic Era Hill University, Dehradun, (10:40AM, 11:15AM) >
meaning the passenger wants to go from Clock tower to Graphic Era Hill University, Dehradun (GEHU) and he would like to be picked up in Clock tower between 10:40 AM and 11:15 AM. Such requests are generally registered though telephone or Internet. It is not necessary that vehicle will take the shortest route, it might deviate from the shortest route to pick some other passenger, but the passenger will be charged based on the shortest distance between the locations that he is travelling. The main objective of the project is to schedule the cabs, in such a way as to maximize the revenue.
You are given n(100) main locations of the city and distances to from each location to some of
its neighboring locations. You can compute the shortest distance from this data (you may assume that every location is reachable from every other location). The amount of money that a passenger will pay to go from location A to B is proportional to the shortest distance from A to B. You can assume that the base rate is Rs.1 per KM.
You are given N (25) vehicles, each of capacity c(5). You can assume that the average speed of these vehicle is 2 minutes per KM. You are also given the location of these vehicles at midnight. You are given R (5000) passenger requests. A request is of the form A, B, t1, t2 implying that the passenger would like to picked up at location A between time t1 and t2 , and he should be dropped at location B. For simplicity, you can assume that all the locations are integers between 1 and n
and the time is in minutes between 0 and 1440, with midnight as reference point. 10:40AM will be noted as 640.
You must write a program to schedule the N vehicles in such a way as to maximize the revenue. You can decide to reject a passenger request (it may not be possible to meet all the requests).
The input will be given in the following format
nN cR
n ∗ n matrix indicating the distances to nearest locations.
A sequence of N locations - indicating where the vehicle is at midnight.
A sequence of R requests.
Expected output of the program is schedule for each vehicle and the total revenue generated.
