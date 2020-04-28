#include <iostream>
#include <vector>
using namespace std;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
void find_minmax(const vector<double>& numbers, double& min, double& max) {
    min=numbers[0];
    max=numbers[0];
    for (size_t i=1; i<numbers.size(); i++)
    {
        if (min>numbers[i])
        {
            min=numbers[i];
        }
        if (max<numbers[i])
        {
            max=numbers[i];
        }}}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count){
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t>count(bin_count,0);
    for (double x: numbers){
        size_t bin_index=(size_t)(x-min)*(bin_count)/(max-min);
        if (bin_index==bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;}
    return count;
}

void show_histogram_text(const vector<size_t>& bins){
    for (size_t bin: bins){
        if (bin<10)
            cout<<"  ";
        else if (bin<100)
            cout<<" ";
        cout<<bin<<"|";

            for(size_t i=0; i<bin; i++)
            {
                cout<<"*";
            }

        cout<<endl;


}}

int main()
{
    size_t number_count;
    cerr<< "enter number count";
    cin>>number_count;
    const auto numbers=input_numbers(number_count);

    size_t bin_count;
    cerr<< "enter bin count";
    cin>>bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_text(bins);
    return 0;

}
