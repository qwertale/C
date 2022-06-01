class GeometricObject 
    attr_reader :color, :filled

    def initialize(color , filled)     	 
    @color = "blue" 
    @filled = "cant_filled" 
    end 
end
      
class Circle < GeometricObject
    attr_reader :color, :filled, :r

    def initialize(color, filled, r)
        super(color, filled)
        @r = r
    end

    def perimeter
        @perimeter ||= 2 * Math::PI * r
    end

    def area
        @area  ||= Math::PI * r * r
    end
    def to_s
        "Circle color = #{@color}\nCircle filled = #{@filled}"
    end
end

class Rectangle < GeometricObject
    attr_reader :color, :filled, :x, :y

    def initialize(color, filled, x, y)
        @color= color
        @filled = filled
        @x = x
        @y = y
        
    end

    def perimeter
        @perimeter ||= 2 * (x + y)
    end

    def area
        @area  ||= x * y
    end
    def to_s
        "Rectangle color = #{@color}\nRectangle filled = #{@filled}"
    end
end

object1 = Circle.new( "boş","boş" , 2) # burdaki boşlar üst sınıftan "super" ile alındı
    
object2 = Rectangle.new("red", "can_filled", 3, 3) 
        
puts "Circle perimeter: #{object1.perimeter}\nCircle area:#{object1.area}"
puts object1
puts "Rectangle perimeter: #{object2.perimeter}\nRectangle area:#{object2.area}"
puts object2
