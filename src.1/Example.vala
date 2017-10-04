/**
 * @see http://stackoverflow.com/questions/7895434/vala-constant-initialization-and-assignment-in-object-constructor
 */
public class Rectangle : GLib.Object {
  public double sideA { get; construct; }
  public double sideB { get; construct; }

  private double? _area = null;
  public double area {
    get {
      if ( _area == null )
        _area = sideA * sideB;

      return _area;
    }
  }

  private double? _diagonal = null;
  public double diagonal {
    get {
      if ( _diagonal == null )
        _diagonal = Math.sqrt(Math.pow(sideA, 2) + Math.pow(sideB, 2));

      return _diagonal;
    }
  }

  public Rectangle (double SideA, double SideB) {
    GLib.Object (
      sideA: SideA,
      sideB: SideB,
      area: SideA * SideB,
      diagonal: Math.sqrt(Math.pow(SideA, 2) + Math.pow(SideB, 2)));
  }
}