import java.util.Scanner;

public abstract class Alumno extends Registro {
    private int codigo;
    private String nombre;

    @Override
    public void cargar(Scanner archivo) {
        this.codigo=archivo.nextInt();
        this.nombre=archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.printf("%-12d%-35s",this.codigo,this.nombre);
    }

    public abstract String getPaisOrigen();
    public abstract double calcularPrecio(Producto producto,double tipoCambio);

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}
