#include<bits/stdc++.h>
using namespace std;
typedef struct
{
    int start_time;
    int end_time;
    int start_loc;
    int end_loc;
    int status=0; 
}request;
typedef struct 
{
  int initial_loc;
  vector<int> route;
  int capacity;
  int revenue;
}vehicle;
void dijkstras (int [5][5], int n, int s);
bool compareRequests(const request &a, const request &b);
void sortRequests(vector<request> &requests);
int calculateRevenue(const request &req, int weight[5][5]);
void assignRequests(vector<request> &requests, vector<vehicle> &vehicles, int weight[5][5]);

int main()
{
   int n_loc = 5, n_veh = 10, c = 5, n_req = 20, i, j;

    vector<vehicle> vehicles(n_veh);
    vehicles[0]={0, {}, 5, 0};
    vehicles[1]={0, {}, 5, 0};
    vehicles[2]={1, {}, 5, 0};
    vehicles[3]={2, {}, 5, 0};
    vehicles[4]={3, {}, 5, 0};
    vehicles[5]={3, {}, 5, 0};
    vehicles[6]={4, {}, 5, 0};
    vehicles[7]={4, {}, 5, 0};
    vehicles[8]={1, {}, 5, 0};
    vehicles[9]={0, {}, 5, 0};
    int weight[5][5] =
    {
        {-1, 10, -1, -1, -1},
        {10, -1, 25, 10, -1},
        {-1, 25, -1, 20, 30},
        {-1, 10, 20, -1, -1},
        {-1, -1, 28, -1, -1},
    };
    for (i = 0; i < n_loc; i++)
    {
        dijkstras(weight, n_loc, i);
    }
    vector<request>requests(n_req);
    requests[0] = {600, 645, 1, 4, 0};
    requests[1] = {610, 623, 5, 1, 0};
    requests[2] = {639, 672, 2, 5, 0};
    requests[3] = {619, 623, 1, 2, 0};
    requests[4] = {640, 720, 1, 5, 0};
    requests[5] = {647, 723, 2, 5, 0};
    requests[6] = {625, 739, 4, 2, 0};
    requests[7] = {700, 745, 1, 4, 0};
    requests[8] = {239, 839, 4, 1, 0};
    requests[9] = {739, 752, 2, 4, 0};
    requests[10] = {719, 923, 1, 3, 0};
    requests[11] = {654, 729, 2, 5, 0};
    requests[12] = {704, 723, 4, 5, 0};
    requests[13] = {625, 739, 4, 2, 0};
    requests[14] = {645, 725, 2, 5, 0};
    requests[15] = {647, 723, 2, 1, 0};
    requests[16] = {655, 739, 4, 3, 0};
    requests[17] = {720, 745, 1, 4, 0};
    requests[18] = {239, 539, 4, 2, 0};
    requests[19] = {390, 752, 2, 4, 0};
    sortRequests(requests);
    for(i=0;i<n_loc;i++)
    {
        dijkstras(weight, n_loc, i);
    }
    for(i=0;i<n_loc;i++)
    {
        for(j=0;j<n_loc;j++)
        {
            cout<<weight[i][j]<<" ";
        }
        cout<<endl;
    }
    assignRequests(requests, vehicles, weight);
    int totalRevenue = 0;
    for (const auto &veh : vehicles)
    {
        totalRevenue += veh.revenue;
    }

    cout << "Final Revenue: " << totalRevenue << endl;
    return 0;
}
void dijkstras(int arr[5][5], int n, int s)
{
    int i, j, start;
    start=s;
    int visited[n]={0};
    long long int weight[n]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    weight[s]=0;
    visited[s]=1;
    for(int index=0;index<n-1;index++)
    {
       for(i=0;i<n;i++)
       {
           if(arr[s][i]+weight[s]<weight[i]&&visited[i]==0&&arr[s][i]>0)
           {
               weight[i]=arr[s][i]+weight[s];
           }
       }
       int min=INT_MAX, mini;
       for(i=0;i<n;i++)
       {
          if(weight[i]<min&&visited[i]==0)
          {
              min=weight[i];
              mini=i;
          }
        }
        s=mini;
        visited[s]=1;
    }
    for(i=0;i<n;i++)
    {
        arr[start][i]=weight[i];
    }
}
bool compareRequests(const request &a, const request &b)
{
    return a.start_time < b.start_time;
}

void sortRequests(vector<request> &requests)
{
    sort(requests.begin(), requests.end(), compareRequests);
}
int  assignRequests(vector<request> &requests, vector<vehicle> &vehicles, int weights[5][5], int totalRevenue)
{
    // Sort vehicles based on their initial_loc
    sort(vehicles.begin(), vehicles.end(), [](const vehicle &a, const vehicle &b) {
        return a.initial_loc < b.initial_loc;
    });

    for (auto &req : requests)
    {
        // Finding the closest available vehicle
        auto minDistVehicle = min_element(vehicles.begin(), vehicles.end(), [&](const vehicle &a, const vehicle &b) {
            int distA = weights[a.initial_loc][req.start_loc];
            int distB = weights[b.initial_loc][req.start_loc];
            return distA < distB;
        });

        if (req.status == 0 && minDistVehicle != vehicles.end() && minDistVehicle->capacity > 1)
        {
            // Assign the request to the closest available vehicle
            minDistVehicle->route.push_back(req.start_loc);
            minDistVehicle->route.push_back(req.end_loc);
            minDistVehicle->capacity--;
            req.status = 1;
            minDistVehicle->revenue += calculateRevenue(req, weights);
        }
    }
}
int calculateRevenue(const request &req, int weights[5][5])
{
    const int baseRate = 1;
    if (weights[req.start_loc][req.end_loc] == -1)
    {
        return 0;
    }
    int distance = weights[req.start_loc][req.end_loc];
    int revenue = baseRate * distance;
    return revenue;
}
