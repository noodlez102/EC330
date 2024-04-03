#include "Graph.h"

Graph::Graph(){
}

void Graph::initVertices(int V){
    numVertices=V;
    adj = new vector<pair<int, int>>[numVertices];
}

int Graph::getNumVertices(){
    return numVertices;
}

void Graph::setNumEdges(int E){
    numEdges=E;
}

int Graph::getNumEdges(){
    return numEdges;
}

void Graph::addEdge(int v, int u, int weight){
    pair<int,int> direct1,direct2;
    direct1.first = u;
    direct1.second = weight;
    adj[v].push_back(direct1);
    direct2.first = v;
    direct2.second = weight;
    adj[u].push_back(direct2);
}

void Graph::print(){
    for(int i =0; i<numVertices;i++){
        cout<<i<<": ";
        for(pair edge: adj[i]){
            cout<< edge.first<<" ("<<edge.second<<") ";
        }
        cout<<endl;
    }
}

void Graph::generateGraph(string fileName){
    ifstream infile(fileName);
    int a,b,d;
    string c;
    infile>>a>>b>>c;
    initVertices(a);
    setNumEdges(b);
    while(infile>>a>>b>>d){
        addEdge(a,b,d);
    }
}

//The modification for this is using a vector to keep track of the number of shortest paths, so in the case of a path of the same length it increments it.

void Graph::numShortestPaths(int source){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> shortestDistances;

    vector<int> shortestPaths;

    shortestDistances.assign(numVertices, INT_MAX); // fills up the vectors 

    shortestPaths.assign(numVertices, 0);



    shortestDistances[source] = 0;

    shortestPaths[source] = 1;



    pq.push({0, source});



    while (!pq.empty()) {

        int u = pq.top().second;

        int dist_u = pq.top().first;

        pq.pop();



        if (dist_u > shortestDistances[u]) {// Skip if we've already found a shorter path

            continue; 

        }



        for (pair<int,int> neighbor : adj[u]) { //for the adjacent neighbors in the adjacency list at the current node

            int v = neighbor.first;

            int weight = neighbor.second;



            if (shortestDistances[u] + weight < shortestDistances[v]) {

                shortestDistances[v] = shortestDistances[u] + weight;

                shortestPaths[v] = shortestPaths[u];

                pq.push({shortestDistances[v], v});

            } else if (shortestDistances[u] + weight == shortestDistances[v]) { //if the new path plus the weight is equal then we can add to the # of shortest paths.

                shortestPaths[v] += shortestPaths[u];

            }

        }

    }



    cout << "Shortest paths from node " << source << ":\n";

    for (int i = 0; i < numVertices; ++i) {

        if(i!=source)

        cout << "Distance to vertex " << i << " is " << shortestDistances[i] << " and there are "<< shortestPaths[i]<<" shortest paths"<<endl;

    }


}

