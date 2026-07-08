import java.util.Scanner;

public class Cliente {
    private int dni;
    private String nombre;
    private double totalGastado;

    public Cliente() {
        this.totalGastado=0;
    }

    public Cliente(int dni) {
        this.dni=dni;
    }

    public int getDni() {
        return dni;
    }

    public String getNombre() {
        return nombre;
    }

    public double getTotalGastado() {
        return totalGastado;
    }

    public boolean leer(Scanner scanner) {
        int dni=scanner.nextInt();
        if (dni>0) {
            this.dni=dni;
            this.nombre=scanner.next();
            return true;
        }
        return false;
    }

    @Override
    public boolean equals(final Object cliente) {
        if (cliente==null || this.getClass()!=cliente.getClass()) return false;
        else return this.dni==((Cliente)cliente).dni;
    }

    public void incrementarTotalGastado(double gasto) {
        this.totalGastado+=gasto;
    }

    public void imprimir() {
        System.out.printf("DNI: %-10d NOMBRE: %-40s",this.dni,this.nombre);
    }
}
