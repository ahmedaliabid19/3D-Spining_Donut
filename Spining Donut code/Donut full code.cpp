//Assignment 3 : Printing A Spining Donut
//Group_members:
//  1) 2021065
//  2) 2021148

#include <iostream>
#include <math.h>
#include <cmath>



using namespace std;

class donut
{
private:
    float r1, r2, x, y, z,z_inv, a, b,L;
    int xp,yp;
public:
    donut() : r1(1.0), r2(2 * r1), x(0), y(0), z(0), a(0), b(0), xp(0), yp(0),z_inv(0), L(0) {}

    void donut_out()
    {
        char output_arr[100][30];
        float z_buffer[100][30];

        char lum[12] = { '.', ',', '-', '~', ':', ';', '=', '!', '*', '#', '$', '@' }; // all the characters that will display lumination..
        int k1 = 25;
        int k2 = 3;
        double PI = 3.141592;

        int i = 0, j = 0;

        while (1)
        {
            //clearing the arrays
            for (int k = 0; k < 100; k++)
            {
                for (int m = 0; m < 30; m++)
                {
                    output_arr[k][m] = ' ';
                    z_buffer[k][m] = 0;
                }
            }
            

            //loop increments 
            float t = 0.1;
            float ph = 0.05;
            

            //to find donut points
            for (float theta = 0; theta < 2 * PI; theta += t)
           
            {
                for (float phi = 0; phi < 2 * PI; phi += ph)
                {
                    x = (r2 + r1 * cos(theta)) * ((cos(b) * cos(phi) + sin(a) * sin(b) * sin(phi)) - (r1 * cos(a) * sin(b) * sin(theta)));
                    y = ((r2 + r1 * cos(theta)) * (cos(phi) * sin(b) - cos(b) * sin(a) * sin(phi)) + (r1 * cos(a) * cos(b) * sin(theta)));
                    z = k2+((cos(a) * (r2 + r1 * cos(theta)) * sin(phi) + r1 * sin(a) * sin(theta)));
                   
                    z_inv = 1 / z;//it helps compare values with x and y as it  gets small and does not reach infinity....


                    xp = 50+(k1 * x) / (k2 + z); 
                                                        //coordinates of 3D object converted to 2D coordinates....
                    yp = 14+ (k1 *0.7* y) / (k2 + z);

                    
                    //lumination......
                    L = ((cos(phi) * cos(theta) * cos(b)) - (cos(a) * cos(theta) * sin(phi))
                        - (sin(a) * sin(theta)) + (cos(b) * (cos(a) * sin(theta) - cos(theta) * sin(a) * sin(phi))));
                   

                    //storing the coordinates...
                    if (  xp < 100 && xp> 0 && yp < 30  && yp > 0 && z_inv > z_buffer[xp][yp] ) /*this condition prevents from storing values that 
                                                                                                    are already stored in output array*/
                    {
                        z_buffer[xp][yp] = z_inv;
                        int new_lum = L * 8;
                        if (new_lum > 0)
                        {
                            output_arr[xp][yp] = lum[new_lum];
                        }
                        else
                            output_arr[xp][yp] = lum[0];
                       


                    }
                }
                
            }

            //printing array...
            
                for (i = 0; i < 30; i++)
                {
                    for (j = 0; j < 100; j++)
                    {
                      /*  cout << output_arr[i][j];*/
                        char print = output_arr[j][i];
                        cout << print;
                    }
                    cout << endl;
                }
            
            system("cls");  // clears the terminal after display of a donut 


            a += 0.2;
            b += 0.2;

        }
        
    }

};
int main()
{
    donut A;  // instance of the donut class...
    A.donut_out();  //call the function to print donut ....
    return 0;
}