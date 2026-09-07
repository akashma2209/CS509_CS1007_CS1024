#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <vector>

using namespace std;

class KMeans
{
private:
    int N;
    int D;
    int K;

    vector<vector<double>> points;
    vector<vector<double>> centroids;
    vector<int> cluster;

    int iterations;
    bool converged;

public:
    KMeans(vector<vector<double>> points, int K);

    void run(int maxIterations, double tolerance);

    double calculateDistance(const vector<double>& p1,const vector<double>& p2);

    double calculateWCSS();

    vector<int> getClusters();

    vector<vector<double>> getCentroids();

    int getIterations();

    bool getConverged();
};

#endif