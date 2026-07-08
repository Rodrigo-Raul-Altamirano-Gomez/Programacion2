import java.util.Scanner;

public class Captura extends Registro {
    private String placa;
    private double velocidad;
    private Carril carril;
    private double latitud;
    private double longitud;
    private String region;
    private String provincia;
    private int km;
    private String fecha;
    private String hora;
    private String codigoCamara;

    @Override
    public void cargar(Scanner archivo) {
        this.placa=archivo.next();
        this.velocidad=archivo.nextDouble();
        int nroCarril=archivo.nextInt();
        this.carril=this.getCarril(nroCarril);
        this.latitud=archivo.nextDouble();
        this.longitud=archivo.nextDouble();
        this.region=archivo.next();
        this.provincia=archivo.next();
        this.km=archivo.nextInt();
        this.fecha=archivo.next();
        this.hora=archivo.next();
        this.codigoCamara=archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.println("DATOS DE LA CAPTURA ELECTRONICA:");
        System.out.println("=========================================================");
        System.out.println("Placa: "+this.placa);
        System.out.println("Velocidad: "+this.velocidad);
        System.out.println("Carril: "+this.carril.getTipo());
        System.out.printf("Ubicacion: Lat %.6f, Lon %.6f\n",this.latitud,this.longitud);
        System.out.println("Region: "+this.region);
        System.out.println("Provincia: "+this.provincia);
        System.out.println("Kilometro: "+this.km);
        System.out.println("Fecha: "+this.fecha);
        System.out.println("Hora: "+this.hora);
        System.out.println("Codigo Camara: "+this.codigoCamara);
    }

    public Carril getCarril(int nroCarril) {
        if (nroCarril==1) return new CarrilEmergencia();
        else if (nroCarril==2) return new CarrilLento();
        else if (nroCarril==3) return new CarrilEstandar();
        else return new CarrilRapido();
    }

    @Override
    public Object clone() {
        Captura capturaClon=new Captura();
        capturaClon.placa=this.placa;
        capturaClon.velocidad=this.velocidad;
        capturaClon.carril=this.getCarril();
        capturaClon.latitud=this.latitud;
        capturaClon.longitud=this.longitud;
        capturaClon.region=this.region;
        capturaClon.provincia=this.provincia;
        capturaClon.km=this.km;
        capturaClon.fecha=this.fecha;
        capturaClon.hora=this.hora;
        capturaClon.codigoCamara=this.codigoCamara;
        return capturaClon;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public Carril getCarril() {
        return carril;
    }

    public void setCarril(Carril carril) {
        this.carril = carril;
    }

    public double getLatitud() {
        return latitud;
    }

    public void setLatitud(double latitud) {
        this.latitud = latitud;
    }

    public double getLongitud() {
        return longitud;
    }

    public void setLongitud(double longitud) {
        this.longitud = longitud;
    }

    public String getRegion() {
        return region;
    }

    public void setRegion(String region) {
        this.region = region;
    }

    public String getProvincia() {
        return provincia;
    }

    public void setProvincia(String provincia) {
        this.provincia = provincia;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public String getCodigoCamara() {
        return codigoCamara;
    }

    public void setCodigoCamara(String codigoCamara) {
        this.codigoCamara = codigoCamara;
    }
}
