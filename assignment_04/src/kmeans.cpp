#include "kmeans.hpp"

#include <cmath>
#include <limits>

using namespace std;


// Constructor
KMeans::KMeans(vector<vector<double>> points, int K)
{
    this->points = points;
    this->K = K;

    N = points.size();
    D = points[0].size();

    cluster.resize(N, 0);

    iterations = 0;
    converged = false;


    // First K points are initial centroids
    for (int i = 0; i < K; i++)
    {
        centroids.push_back(points[i]);
    }
}


// Calculate Euclidean distance
double KMeans::calculateDistance(const vector<double>& p1,const vector<double>& p2)
{
    double sum = 0.0;

    for (int i = 0; i < D; i++)
    {
        double difference = p1[i] - p2[i];

        sum += difference * difference;
    }

    return sqrt(sum);
}


// K-Means algorithm
void KMeans::run(int maxIterations, double tolerance)
{
    converged = false;
    iterations = 0;


    for (int iteration = 0; iteration < maxIterations; iteration++)
    {
        
        // STEP 1: ASSIGN POINTS TO CLUSTERS
        

        bool changed = false;

        for (int i = 0; i < N; i++)
        {
            double minimumDistance = numeric_limits<double>::max();

            int nearestCluster = 0;

            // Find nearest centroid
            for (int j = 0; j < K; j++)
            {
                double distance =calculateDistance(points[i], centroids[j]);

                if (distance < minimumDistance)
                {
                    minimumDistance = distance;
                    nearestCluster = j;
                }
            }


            // Check if cluster changed
            if (cluster[i] != nearestCluster)
            {
                changed = true;
            }

            cluster[i] = nearestCluster;
        }


        
        // STEP 2: CALCULATE NEW CENTROIDS
        

        vector<vector<double>> newCentroids( K,vector<double>(D, 0.0));

        vector<int> count(K, 0);


        // Add points belonging to each cluster
        for (int i = 0; i < N; i++)
        {
            int c = cluster[i];

            count[c]++;

            for (int j = 0; j < D; j++)
            {
                newCentroids[c][j] += points[i][j];
            }
        }


        // Calculate average
        for (int i = 0; i < K; i++)
        {
            // Empty cluster
            // Keep old centroid
            if (count[i] == 0)
            {
                newCentroids[i] = centroids[i];
            }
            else
            {
                for (int j = 0; j < D; j++)
                {
                    newCentroids[i][j] /=
                        count[i];
                }
            }
        }


        
        // STEP 3: CHECK CENTROID SHIFT
        

        double maximumShift = 0.0;


        for (int i = 0; i < K; i++)
        {
            double shift =calculateDistance(centroids[i], newCentroids[i]);

            if (shift > maximumShift)
            {
                maximumShift = shift;
            }
        }

        // Save new centroids
        centroids = newCentroids;
        // Count this iteration
        iterations++;
        // STEP 4: CHECK CONVERGENCE
    
        if (!changed || maximumShift <= tolerance)
        {
            converged = true;
            break;
        }
    }
}


// Calculate WCSS
double KMeans::calculateWCSS()
{
    double wcss = 0.0;

    for (int i = 0; i < N; i++)
    {
        int c = cluster[i];
        double distance =calculateDistance(points[i], centroids[c]);
        wcss += distance * distance;
    }


    return wcss;
}


// Get cluster assignments
vector<int> KMeans::getClusters()
{
    return cluster;
}


// Get centroids
vector<vector<double>> KMeans::getCentroids()
{
    return centroids;
}


// Get number of iterations
int KMeans::getIterations()
{
    return iterations;
}


// Get convergence status
bool KMeans::getConverged()
{
    return converged;
}