import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Libro {
    private String codigo;
    private String titulo;
    private String autor;
    private double precio;
    private ArrayList<Venta> ventas;
    private int suma;
    private int ranking;
    private double totalVendido;

    public Libro() {
        this.ventas=new ArrayList<>();
        this.suma=0;
        this.totalVendido=0;
    }

    public Libro(final String codigo) {
        this.codigo=codigo;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public double getPrecio() {
        return precio;
    }

    public List<Venta> getVentas() {
        return Collections.unmodifiableList(ventas);
    }

    public int getSuma() {
        return suma;
    }

    public int getRanking() {
        return ranking;
    }

    public double getTotalVendido() {
        return totalVendido;
    }

    public boolean leer(Scanner scanner) {
        String codigo=scanner.next();
        if (!codigo.equals("FIN")) {
            this.codigo=codigo;
            this.titulo=scanner.next();
            this.autor=scanner.next();
            this.precio=scanner.nextDouble();
            return true;
        }
        return false;
    }

    @Override
    public boolean equals(final Object libro) {
        if (libro==null || this.getClass()!=libro.getClass()) return false;
        else return this.codigo.equals(((Libro)libro).codigo);
    }

    public void aniadirVenta(final Venta venta) {
        this.ventas.add(venta);
        this.suma+=venta.getCalificacion();
        this.totalVendido+=this.precio;
    }

    public void calcularRanking() {
        double promedioPuntajes=0;
        if (!this.ventas.isEmpty()) {
            promedioPuntajes=(double)this.suma/this.ventas.size();
            if (promedioPuntajes<25) this.ranking=1;
            else if (promedioPuntajes<50) this.ranking=2;
            else if (promedioPuntajes<75) this.ranking=3;
            else this.ranking=4;
        }
        else this.ranking=0;
    }

    public void imprimir(final ArrayList<Cliente> clientes) {
        int cont=1;
        System.out.printf("CODIGO: %-10s TITULO: %-30s AUTOR: %-25s PRECIO: %.2f\n",this.codigo,this.titulo,this.autor,
                this.precio);
        System.out.printf("LIBROS VENDIDOS: %-5d RANKING: %d\n\n",this.ventas.size(),this.ranking);
        System.out.println("VENTAS REALIZADAS:");
        for (Venta venta : this.ventas) {
            Cliente clienteClave=new Cliente(venta.getDni());
            int posCliente=clientes.indexOf(clienteClave);
            System.out.printf("No. %-3d",cont);
            if (posCliente>=0) clientes.get(posCliente).imprimir();
            venta.imprimir();
            cont++;
        }
    }
}
