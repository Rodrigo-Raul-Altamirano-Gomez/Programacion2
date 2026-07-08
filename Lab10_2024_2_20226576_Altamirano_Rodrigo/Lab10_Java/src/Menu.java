import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Menu {
    private final List<Producto> productos;

    public Menu() {
        this.productos=new ArrayList<>();
    }

    public void cargarProductos(Scanner archivo) {
        while (archivo.hasNext()) {
            char tipoProducto=archivo.next().charAt(0);
            Producto producto;
            if (tipoProducto=='B') producto=new Bebida();
            else producto=new Helado();
            producto.cargar(archivo);
            this.productos.add(producto);
        }
    }

    public void imprimirMenu() {
        System.out.printf("%-20s Menu del dia %-20s\n","=","=");
        for (Producto producto : this.productos) {
            producto.imprimir();
            System.out.println("---------------------------------------------------------------");
        }
    }

    public void imprimirMenuPersonalizado(Alumno alumno, Pais pais) {
        System.out.printf("%-10s Menu en %s(%s) para, %d:%s %10s\n","=",pais.getIdioma(),pais.getNombre(),
                alumno.getCodigo(),alumno.getNombre(),"=");
        for (Producto producto : this.productos) {
            producto.imprimir(alumno,pais);
            System.out.println("---------------------------------------------------------------");
        }
    }
}
