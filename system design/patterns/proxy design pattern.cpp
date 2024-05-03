
#include <iostream>
#include <string>

// Subject Interface
/*
The Image interface defines the common operations that both the RealImage and ProxyImage classes must implement. 
This interface typically consists of one or more methods that define the functionality expected from objects representing images. 
In our example, the Image interface declares a single method:

Abstracts the behavior of an image.
Provides a common interface that RealImage and ProxyImage adhere to.
*/
class Image {
public:
    virtual void display() = 0;
};

// RealSubject

/*
The RealImage class represents the real object that performs the actual loading and display of an image. 
It implements the Image interface and handles the concrete operations related to loading and displaying an image from disk.

Represents the real object that does the heavy lifting (image loading).
Implements the Image interface by providing concrete behavior for the display method.
Manages the actual loading of image data from disk.
*/
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk(filename);
    }

    void display() override {
        std::cout << "Displaying " << filename << std::endl;
    }

private:
    void loadFromDisk(const std::string& filename) {
        std::cout << "Loading " << filename << " from disk" << std::endl;
        // Simulate loading image data from disk
    }
};

// Proxy
/*
The ProxyImage class acts as a proxy or placeholder for a RealImage object. 
It implements the Image interface and controls access to the RealImage, which it instantiates lazily when needed.

Acts as a surrogate or placeholder for the RealImage object.
Implements the Image interface, thereby providing a consistent interface to clients.
Controls access to the RealImage by creating it only when needed (lazy initialization).
Delegates the display operation to the RealImage object once it's instantiated.
*/
class ProxyImage : public Image {
private:
    std::string filename;
    RealImage* realImage;

public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    // Using Proxy to control access to RealImage
    Image* image1 = new ProxyImage("image1.jpg");

    // Image will be loaded from disk only when display is called
    image1->display();
    std::cout << std::endl;

    // Image will not be reloaded from disk, as it's already loaded
    image1->display();
    std::cout << std::endl;

    // Using Proxy with a different image
    Image* image2 = new ProxyImage("image2.jpg");

    // This image will be loaded from disk on first display call
    image2->display();
    std::cout << std::endl;

    delete image1;
    delete image2;

    return 0;
}
