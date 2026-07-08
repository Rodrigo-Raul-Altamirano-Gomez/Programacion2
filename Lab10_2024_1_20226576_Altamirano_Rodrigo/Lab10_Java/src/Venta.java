import java.util.Scanner;

public class Venta {
    private int dni;
    private int calificacion;
    private int fecha;

    public Venta() {
        this.dni=0;
    }

    public int getDni() {
        return dni;
    }

    public int getCalificacion() {
        return calificacion;
    }

    public int getFecha() {
        return fecha;
    }

    public void leer(Scanner scanner) {
        int dia,mes,anio;
        this.dni=scanner.nextInt();
        this.calificacion=scanner.nextInt();
        dia=scanner.nextInt();
        mes=scanner.nextInt();
        anio=scanner.nextInt();
        this.fecha=dia+mes*100+anio*10000;
    }

    public void imprimir() {
        System.out.printf("CALIFICACION: %d\n",this.calificacion);
    }
}
