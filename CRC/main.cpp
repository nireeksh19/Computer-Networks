#include <iostream>
using namespace std;
int main()
{
    int c[50], b[50], a[4] = {1, 0, 0, 1};
    int i, j, m, n = 4, x, y, z, e, pos, fail = 1;
    cout << "Enter number of bits in messages:\n";
    cin >> m;
    cout << "Enter the message to be transmitted:\n";
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
        c[i] = b[i];
    }
    for (i = m; i < m + n - 1; i++)
        b[i] = 0;
    if (m < n)
    {
        cout << "Error !! Enter the bits again";
        exit(0);
    }
    else
    {
        y = 0;
        for (i = 0; i < m; i++)
        {
            if (b[y] == 1)
                for (x = y, j = 0; x < y + n; x++, j++)
                    b[x] = b[x] ^ a[j];
            else
                for (x = y; x < y + n; x++)
                    b[x] = b[x] ^ 0;
            y++;
        }
    }

    for (i = m; i < m + n - 1; i++)
        c[i] = b[i];
    cout << "Message to be sent is:\n";
    for (i = 0; i < m + n - 1; i++)
        cout << c[i] << " ";
    cout << "\nDo you want to introduce error? yes = 1 or No = 0:\n";
    cin >> e;
    if (e == 1)
    {
        cout << "Enter the position to be changed:";
        cin >> pos;
        if (pos > m)
            cout << "\nInvalid position";
        else if (c[pos - 1] == 0)
            c[pos - 1] = 1;
        else
            c[pos - 1] = 0;
    }
    cout << "Message received at receiver site:\n";
    for (i = 0; i < m + n - 1; i++)
        cout << c[i] << " ";
    z = 0;
    for (i = 0; i < m; i++)
    {
        if (c[z] == a[0])
        {
            for (x = z, j = 0; x < z + n; x++, j++)
                c[x] = c[x] ^ a[j];
        }
        else
        {
            for (x = z; x < z + n; x++)
                c[x] = c[x] ^ 0;
        }
        z++;
    }
    for (i = 0; i < m + n - 1; i++)
    {
        if (c[i] == 1)
        {
            cout << "\n!!! There is Error in the message !!!\n";
            fail = 0;
            break;
        }
    }
    if (fail)
        cout << "\nSuccessfully transfered the message\n";
}
