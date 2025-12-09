interface Resizable {
    void resizeWidth(int width);
    void resizeHeight(int height);
}

class Rectangle implements Resizable {
    private int width;
    private int height;
    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }
    public void resizeWidth(int width) {
        this.width = width;
        System.out.println("Resized width to: " + width);
    }
    public void resizeHeight(int height) {
        this.height = height;
        System.out.println("Resized height to: " + height);
    }
    public int getWidth() {
        return width;
    }
    public int getHeight() {
        return height;
    }
    public void displayInfo() {
        System.out.println("Rectangle: Width = " + width + ", Height = " + height);
    }
}

public class ResizeDemo {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(10, 5);
        System.out.println("Original Rectangle Info:");
        rectangle.displayInfo();
        rectangle.resizeWidth(15);
        rectangle.resizeHeight(8);
        System.out.println("\nUpdated Rectangle Info:");
        rectangle.displayInfo();
    }
}
