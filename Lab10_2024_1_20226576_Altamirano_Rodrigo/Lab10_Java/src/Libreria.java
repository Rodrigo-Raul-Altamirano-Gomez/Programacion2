import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Libreria {
    private String nombre;
    private String direccion;
    private ArrayList<Libro> libros;
    private ArrayList<Cliente> clientes;
    private int cantidadVendida;
    private double totalVendido;

    public Libreria() {
        libros=new ArrayList<>();
        clientes=new ArrayList<>();
        cantidadVendida=0;
        totalVendido=0;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public List<Libro> getLibros() {
        return Collections.unmodifiableList(libros);
    }

    public List<Cliente> getClientes() {
        return Collections.unmodifiableList(clientes);
    }

    public int getCantidadVendida() {
        return cantidadVendida;
    }

    public double getTotalVendido() {
        return totalVendido;
    }

    public void leer() throws FileNotFoundException {
        Scanner scanner=new Scanner(new File("ArchivosDeDatos/VentaDeLibros.txt"));
        this.nombre=scanner.next();
        this.direccion=scanner.next();
        this.cargarLibros(scanner);
        this.cargarClientes(scanner);
        this.completarLibros(scanner);
    }

    private void cargarLibros(Scanner scanner) {
        while (true) {
            Libro libro=new Libro();
            if (!libro.leer(scanner)) break;
            this.libros.add(libro);
        }
    }

    private void cargarClientes(Scanner scanner) {
        while (true) {
            Cliente cliente=new Cliente();
            if (!cliente.leer(scanner)) break;
            this.clientes.add(cliente);
        }
    }

    private void completarLibros(Scanner scanner) {
        while (scanner.hasNext()) {
            String codLibro=scanner.next();
            Venta venta=new Venta();
            venta.leer(scanner);
            Libro libroClave=new Libro(codLibro);
            Cliente clienteClave=new Cliente(venta.getDni());
            int posLibro=this.libros.indexOf(libroClave);
            int posCliente=this.clientes.indexOf(clienteClave);
            if (posLibro>=0 && posCliente>=0) {
                Libro libro=this.libros.get(posLibro);
                libro.aniadirVenta(venta);
                this.clientes.get(posCliente).incrementarTotalGastado(libro.getPrecio());
                this.cantidadVendida++;
                this.totalVendido+=libro.getPrecio();
            }
        }
    }

    public void calcularRankings() {
        for (Libro libro : this.libros) {
            libro.calcularRanking();
        }
    }

    public void imprimir() {
        int cont=1;
        System.out.println(this.nombre);
        System.out.println(this.direccion);
        System.out.println("RESULTADO DE LAS VENTAS REALIZADAS:");
        for (Libro libro : this.libros) {
            System.out.printf("\nLIBRO NO. %d\n",cont);
            libro.imprimir(this.clientes);
            cont++;
        }
    }
}
