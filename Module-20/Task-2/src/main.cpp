#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Get image dimensions (width, height) from the user.
void getImageSizeFromUser(unsigned& width, unsigned& height);

// Generate a picture and save it to an array.
void generatePicture(vector<char>& picture, const unsigned width);

int main()
{
    cout << "Task 20.2 Drawing random pictures\n"
         << "------------------------------------\n\n";

    string   filePath{"pic.txt"};
    ofstream file(filePath);

    if (!file) {
        cerr << "Error: Failed to open file \"" << filePath << "\"";
        cin.get();
        return EXIT_FAILURE;
    }

    unsigned width;
    unsigned height;
    getImageSizeFromUser(width, height);

    vector<char> picture(width * height + height);
    generatePicture(picture, width);

    file.write(picture.data(), static_cast<streamsize>(picture.size()));
    file.close();

    cout << "\nPicture successfully generated!\n";

    cin.get();
    return 0;
}

void getImageSizeFromUser(unsigned& width, unsigned& height)
{
    int maxSize = 8192;
    string input;
    istringstream iss;

    while (true) {
        cout << "Enter the image width and height in pixels (max is 8192): ";
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start != string::npos) {
            int w, h;
            iss.str(input.substr(start, last - start + 1));
            iss >> w >> h;

            if (iss && iss.eof() && (w >= 0 && w <= maxSize) && (h >= 0 && h <= maxSize)) {
                width  = static_cast<unsigned>(w);
                height = static_cast<unsigned>(h);
                return;
            }
        }
        cerr << "Error: Invalid input\n\n";
        iss.clear();
    }
}

void generatePicture(vector<char>& picture, const unsigned width)
{
    srand(time(nullptr));
    for (size_t i = 0; i < picture.size(); i++) {
        // If the index is equal to the width of the image then write '\n', otherwise a random character '0' or '1'
        picture[i] = (i % (width + 1) == width) ? '\n' : ('0' + (rand() % 2));
    }
}
