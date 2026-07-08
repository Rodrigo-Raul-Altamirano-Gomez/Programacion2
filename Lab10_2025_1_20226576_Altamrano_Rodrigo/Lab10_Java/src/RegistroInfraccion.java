public class RegistroInfraccion {
    private String codigoInfraccion;
    private double monto;
    private int puntos;
    private Captura captura;
    private Vehiculo vehiculo;

    public RegistroInfraccion(String codigoInfraccion,double monto,int puntos,Captura captura,Vehiculo vehiculo) {
        this.codigoInfraccion=codigoInfraccion;
        this.monto=monto;
        this.puntos=puntos;
        this.captura=(Captura) captura.clone();
        this.vehiculo=(Vehiculo) vehiculo.clone();
    }

    public String getCodigoInfraccion() {
        return codigoInfraccion;
    }

    public void setCodigoInfraccion(String codigoInfraccion) {
        this.codigoInfraccion = codigoInfraccion;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public int getPuntos() {
        return puntos;
    }

    public void setPuntos(int puntos) {
        this.puntos = puntos;
    }

    public Captura getCaptura() {
        return (Captura) captura.clone();
    }

    public void setCaptura(Captura captura) {
        this.captura = (Captura) captura.clone();
    }

    public Vehiculo getVehiculo() {
        return (Vehiculo) vehiculo.clone();
    }

    public void setVehiculo(Vehiculo vehiculo) {
        this.vehiculo = (Vehiculo) vehiculo.clone();
    }
}
