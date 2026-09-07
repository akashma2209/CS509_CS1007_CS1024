#include "FastMap.hpp"
#include <cmath>

using namespace std;

void fastMap(
    double **distance,
    int objects,
    int targetDimensions,
    double **coordinates,
    int pivotA[],
    int pivotB[]
)
{
    // Initialize all coordinates to zero
    for(int i = 0; i < objects; i++)
    {
        for(int j = 0; j < targetDimensions; j++)
        {
            coordinates[i][j] = 0.0;
        }
    }

    // FastMap for each target dimension
    for(int dim = 0; dim < targetDimensions; dim++)
    {
        // Choose a starting object for pivot search
        // Kept fixed for reproducible results
        int startObject = 0;

        // Find the object farthest from the starting object
        int a = startObject;
        double maxDistance = -1.0;

        for(int i = 0; i < objects; i++)
        {
            if(distance[startObject][i] > maxDistance)
            {
                maxDistance = distance[startObject][i];
                a = i;
            }
        }

        // Find the object farthest from pivot A
        int b = a;
        maxDistance = -1.0;

        for(int i = 0; i < objects; i++)
        {
            if(distance[a][i] > maxDistance)
            {
                maxDistance = distance[a][i];
                b = i;
            }
        }

        // Store the selected pivots
        pivotA[dim] = a;
        pivotB[dim] = b;

        double pivotDistance = distance[a][b];

        // If pivots are identical, this dimension has no information
        if(pivotDistance == 0.0)
        {
            for(int i = 0; i < objects; i++)
            {
                coordinates[i][dim] = 0.0;
            }

            continue;
        }

        // Calculate coordinate using the law of cosines
        for(int i = 0; i < objects; i++)
        {
            double distanceA = distance[a][i];
            double distanceB = distance[b][i];

            double numerator =
                (distanceA * distanceA) +
                (pivotDistance * pivotDistance) -
                (distanceB * distanceB);

            coordinates[i][dim] =
                numerator / (2.0 * pivotDistance);
        }

        // Deflate the distance matrix by removing
        // the contribution of the current dimension
        for(int i = 0; i < objects; i++)
        {
            for(int j = i + 1; j < objects; j++)
            {
                double coordinateDifference =
                    coordinates[i][dim] - coordinates[j][dim];

                double remainingDistance =
                    (distance[i][j] * distance[i][j]) -
                    (coordinateDifference * coordinateDifference);

                // Avoid small negative values due to floating-point error
                if(remainingDistance < 0.0)
                {
                    remainingDistance = 0.0;
                }

                distance[i][j] = sqrt(remainingDistance);
                distance[j][i] = distance[i][j];
            }
        }
    }
}
