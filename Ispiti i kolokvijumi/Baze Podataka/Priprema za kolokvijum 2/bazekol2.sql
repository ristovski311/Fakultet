create view sek_info AS
select s.naziv, avg(plata) prosek, count(*) brojrad
from sektor join radnik on r.brs = s.br
group by sektor


--JUN2 2023

--A

CREATE VIEW INFORMACIJE AS
SELECT T.NAZIV || ' ' || T.DATUM NAZIV_I_DATUM, 
        COUNT(A.ID) UKUPNO_TAKMICARA, 
        (EXTRACT(YEAR FROM SYSDATE) - AVG(AT.GOD_RODJ)) PROSECNA_STAROST
FROM TAKMICENJE T 
    JOIN ATLETICAR_TAKMICENJE AT ON AT.TAKMICENJE_ID = T.ID 
    JOIN ATLETICAR A ON AT.ATLETICAR_ID = A.ID
GROUP BY T.NAZIV, T.DATUM

--B

UPDATE ATLETICAR SET NAPOMENA = 'Senior'
WHERE ID IN
(
    SELECT AT.ATLETICAR_ID
    FROM ATLETICAR_TAKMICENJE AT JOIN TAKMICENJE T ON AT.TAKMICENJE_ID = T.ID
    WHERE T.DUZINA > 1500
    GROUP BY AT.ATLETICAR_ID
    HAVING COUNT(*) > 3
    MINUS
    SELECT AT.ATLETICAR_ID
    FROM FROM ATLETICAR_TAKMICENJE AT JOIN TAKMICENJE T ON AT.TAKMICENJE_ID = T.ID
        JOIN ATLETICAR A ON A.ID = AT.ATLETICAR_ID
    WHERE T.DUZINA = 400 AND EXTRACT(YEAR FROM SYSDATE) - A.GOD_RODJ > 18
)

--C

DELETE FROM TAKMICENJE
WHERE ID IN
(
    SELECT T.ID
    FROM TAKMICENJE T JOIN ATLETICAR_TAKMICENJE AT ON AT.TAKMICENJE_ID = T.ID
    WHERE T.DATUM - SYSDATE <= 10 AND T.NAZIV LIKE '%Open%'
    GROUP BY T.ID
    HAVING COUNT(AT.ATLETICAR_ID) < 20
)

--D

Main()
{
string conString;
OracleConnection con = null;
try
{
    conString = "Data Source=...; User Id=...; Password=...;"
    con = new OracleConnection(conString);
    con.Open();

    string ime;
    string prezime;

    Console.WriteLine("Unesite ime:\n");
    ime = Console.ReadLine();
    Console.WriteLine("Unesite prezime:\n");
    prezime = Console.ReadLine();

    OracleCommand command = new OracleCommand("SELECT T.NAZIV, T.DATUM 
                                               FROM ATLETICAR A JOIN ATLETICAR_TAKMICENJE AT ON A.ID = AT.ATLETICAR_ID
                                               JOIN TAKMICENJE T ON T.ID = AT.TAKMICENJE_ID
                                               WHERE A.IME = :ime AND A.PREZIME = :prezime", con);

    OracleParameter parametarIme = new OracleParameter("ime", OracleDbType.Varchar(30));
    OracleParameter parametarPrezime = new OracleParameter("prezime", OracleDbType.Varchar(30));

    command.Parameters.Add(parametarIme);
    command.Parameters.Add(parametarPrezime);

    parametarIme.Value = (Object)ime;
    parametarPrezime.Value = (Object)prezime;

    OracleDataReader dr = command.ExecuteReader();
    
    if(!dr.HasRows)
        return;

    while(dr.Read())
    {
        string ime1 = dr.GetString(0);
        string prezime1 = dr.GetString(1);

        Console.WriteLine("Ime: " + ime1 + " Prezime: " + prezime1);
    }


}
catch(Exception ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if(con != null && con.State == System.Data.ConnectionState.Open)
    con.Close();
}

}



--JUN 2023

--A

    CREATE VIEW INFORMACIJE AS
    SELECT  S.ID, S.NAZIV, Z.STRUCNA_SPREMA, COUNT(Z.ID) BROJ_ZAPOSLENIH, COUNT(DISTINCT P.NAZIV) BROJ_RAZL_POZICIJA, AVG(P.DATUM_KRAJA - P.DATUM_POC) PROSECNO_VREME_ANG
    FROM POZICIJA P JOIN ZAPOSLENI Z ON P.ZAPOSLENI_ID = Z.ID JOIN SEKTOR S ON S.ID = P.SEKTOR_ID
    WHERE EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM DATUM_POC) < 6
    GROUP BY Z.STRUCNA_SPREMA, S.ID, S.NAZIV

--B

    UPDATE ZAPOSLENI SET PLATA = PLATA * 1.2
    WHERE EXTRACT(YEAR FROM SYSDATE) - GOD_RODJENJA < 40
    AND ID IN
    (
        SELECT P.ZAPOSLENI_ID 
        FROM POZICIJA P JOIN SEKTOR S ON P.SEKTOR_ID = S.ID
        WHERE S.NAZIV = 'PRODAJA'
        GROUP BY P.ZAPOSLENI_ID
        HAVING COUNT(P.ZAPOSLENI_ID) = 3
    )

--C

    DELETE FROM POZICIJA
    WHERE SEKTOR_ID IN
    (
        SELECT ID
        FROM SEKTOR
        WHERE NAZIV = 'PRODAJA'
    )
    AND ZAPOSLENI_ID IN
    (
        SELECT ID
        FROM ZAPOSLENI
        WHERE STRUCNA_SPREMA = 7
    )
    AND DATUM_KRAJA IS NOT NULL
    AND (DATUM_KRAJA - DATUM_POC) < 60


--D

Main()
{
    OracleConnection con = null;
    string constring;

    try
    {
        constring = "Data Source = ...; User Id = ...; Password = ...;";
        con = new OracleConnection(constring);

        con.Open();

        Console.WriteLine("Uneti id zaposlenog!");
        int id = Convert.ToInt32(Console.ReadLine());

        OracleCommand command = new OracleCommand("SELECT P.NAZIV, S.NAZIV 
                                    FROM POZICIJA P JOIN SEKTOR S ON P.SEKTOR_ID = S.ID
                                    WHERE P.ZAPOSLENI_ID = :id", con);

        OracleParameter param1 = new OracleParameter("id", OracleDbType.Int32);
        param1.Value = id;
        command.Parameters.Add(id);

        OracleDataReader dr = command.ExecuteReader();

        if(!dr.HasRows)
            return;

        while(dr.Read())
        {
            string pozicija = dr.GetString(0);
            string sektor = dr.GetString(1);

            Console.WriteLine($"Pozicija: {pozicija}, sektor: {sektor}");
        }
    }
    catch(Exception ex)
    {
        Console.WriteLine(ex.Message);
    }
    finally
    {
        if(con != null && con.State == System.Data.ConnectionState.Open)
            con.Close();
    }
}

--APR 2023

--A

CREATE VIEW INFORMACIJE AS
SELECT V1.ID, V2.NAZIV, COUNT(V1.ID) BROJ_VERZIJA, COUNT(DISTINCT V1.DIR_ID) BROJ_DIR, AVG(V1.BROJ_LINIJA)
FROM VERZIJE V1 JOIN VERZIJE V2 ON V1.ORIG_FAJL_ID = V2.ID
GROUP BY V2.ID, V2.NAZIV

--B

UPDATE VERZIJE SET BROJ_LINIJA = BROJ_LINIJA + 20
WHERE ORIG_FAJL_ID IS NULL 
AND ID NOT IN 
(
    SELECT DISTINCT ORIG_FAJL_ID FROM VERZIJE
)
AND SYSDATE - DATUM <= 10
AND PROG_ID IN 
(
    SELECT ID
    FROM PROGRAMER 
    WHERE JEZIK = 'PHP'
)
AND DIR_ID IN 
(
    SELECT D.ID 
    FROM DIREKTORIJUM D JOIN VERZIJE V ON V.DIR_ID = D.ID 
    WHERE D.NAZIV LIKE '%projekat%' AND V.ORIG_FAJL_ID IS NOT NULL
    GROUP BY D.ID
    HAVING COUNT(V.ID) > 2
)


--C

DELETE FROM DIREKTORIJUM 
WHERE ID NOT IN 
(
    SELECT DISTINCT ROD_DIR_ID FROM DIREKTORIJUM
)
AND ID NOT IN 
(
    SELECT DISTINCT DIR_ID
    FROM VERZIJE
    WHERE ORIG_FAJL_ID IS NULL
)

--D

Main()
{
    OracleConnection con = null;
    string constring;

    try
    {
        constring = "Data Source = ...; User Id = ...; Password = ...;";
        con = new OracleConnection(constring);

        int id = Convert.ToInt32(Console.ReadLine());

        OracleCommand command = new OracleCommand("UPDATE VERZIJE SET ORIG_FAJL_ID = NULL
                                                   WHERE ORIG_FAJL_ID IS NOT NULL
                                                   AND DIR_ID = :id;", con);

        OracleParameter paramId = new OracleParameter("id", OracleDbType.Int32);
        
        paramId.Value = (Object)id;
        command.Parameters.Add(paramId);
       

        command.ExecuteNonQuery();
    }
    catch(Exception ex)
    {
        Console.WriteLine(ex.Message);
    }
    finally
    {
        if(con != null && con.State == System.Data.ConnectionState.Open)
            con.Close();
    }
}


--JAN23

--A

CREATE VIEW STATISTIKA AS
SELECT V.ID, V.KM, V.GODPROIZV, K.NAZIV, (P.DAT_POC - P.DAT_KRAJA) UKUPNO_PRACENO,  COUNT(JMBG) PRATILO
FROM VOZILO V JOIN PRATI P ON V.ID = P.IDVOZILA JOIN KOMPANIJA K ON K.PIB = V.PIBFIR
GROUP BY V.ID, V.KM, V.GODPROIZV, K.NAZIV;

SELECT * FROM STATISTIKA
WHERE YEAR(SYSDATE) - GODPROIZV > 7 AND PRATILO >= 3;

--B

UPDATE ZAPOSLENI SET PLATA = PLATA * 1.2
WHERE PLATA < (SELECT AVG(PLATA) FROM ZAPOSLENI)
AND JMBG IN 
(
    SELECT P.JMBG 
    FROM PRATI P JOIN VOZILO V ON V.ID = P.IDVOZILA JOIN KOMPANIJA K ON V.PIBFIR = K.PIB
    WHERE K.GRAD = 'BEOGRAD'
    GROUP BY P.JMBG
    HAVING COUNT(V.ID) > 1
)

--C

DELETE FROM PRATI
WHERE (DATUM_KRAJA - DATUM_POC) < 3
AND JMBG IN
(
    SELECT JMBG
    FROM ZAPOSLENI
    WHERE GOD_STAZA > 15
)
AND IDVOZILA IN
(
    SELECT V.ID
    FROM VOZILO V
    WHERE V.GORIVO = 'DIZEL'
    AND V.PIBFIR IN
    (
        SELECT PIBFIR
        FROM VOZILO
        GROUP BY PIBFIR
        HAVING COUNT(*) > 5
        
    )
) 

--D

Main()
{
    OracleConnection con = null;
    string conString;

    try
    {
        conString = "Data Source = ...; User Id=...; Password = ...;";
        con = new OracleConnection(conString);

        OracleCommand command = new OracleCommand("SELECT K.NAZIV, K.GRAD 
                                                   FROM ZAPOSLENI Z JOIN PRATI P ON Z.JMBG = P.JMBG
                                                   JOIN VOZILO V ON P.IDVOZILA = V.ID
                                                   JOIN KOMPANIJA K ON K.PIB = V.PIBFIR
                                                   WHERE Z.IME = :ime
                                                   AND Z.PREZIME = :prezime;", con);

        OracleParameter paramIme = new OracleParameter("ime", OracleDbType.Varchar(30));
        OracleParameter paramPrezime = new OracleParameter("prezime", OracleDbType.Varchar(30));

        Console.WriteLine("Uneti ime:");
        paramIme.Value = (object)Console.ReadLine();
        Console.WriteLine("Uneti prezime:");
        paramPrezime.Value = (object)Console.ReadLine();

        command.Parameters.Add(paramIme);
        command.Parameters.Add(paramPrezime);

        OracleDataReader dr = command.ExecuteReader();

        if(!dr.HasRows)
            return;

        while(dr.Read())
        {
            string naziv = dr.GetString(0);
            string grad = dr.GetString(1);

            Console.WriteLine("Naziv: " + naziv + " grad: " + grad);
        }

        dr.Close();
    }
    catch(Exception ex)
    {
        Console.WriteLine(ex.Message);
    }
    finally
    {
        if(con != null && con.State = System.Data.ConnectionState.Open)
            con.Close();
    }
}


--DEC 22

--A

CREATE VIEW IGRAC_STAT AS
SELECT S.IME, S.PREZIME, (YEAR(SYSDATE) - S.GOD_ROD) GODINA, S.PLATA, COUNT(ID_KLUBA) IGRALI_U
FROM SPORTISTA S JOIN CLAN C ON C.ID_SPORTISTE = S.ID
GROUP BY S.ID, S.IME, S.PREZIME

SELECT *
FROM IGRAC_STAT
WHERE IGRALI_U >= 2

--B

ALTER TABLE SPORTISTA SET PLATA = PLATA * 0.97
WHERE GRAD = "NOVI SAD"
AND ID IN
(
    SELECT C.ID_SPORTISTE
    FROM CLAN C JOIN KLUB K ON K.ID = C.ID_KLUBA
    WHERE K.SPORT = 'ODBJOKA'
    AND C.TIM = 'PRVI'
    AND C.DATUM_DO IS NULL
)


--C

DELETE FROM CLAN
WHERE ID_KLUBA IN
(
    SELECT ID
    FROM KLUB
    WHERE (YEAR(SYSDATE) - GOD_OSNIVANJA) > 20
)
AND TIM = 'SKOLA'
AND NOT EXISTS 
(
    SELECT 0
    FROM CLAN C1
    WHERE TIM = 'MLADI'
    AND C1.ID_SPORTISTE = ID_SPORTISTE AND C1.ID_KLUBA = ID_KLUBA

)


--D

string conString;
OracleConnection con = null;
try
{
    constring = "Data Source = ...; User Id=...; Password = ...;";
    con = new OracleConnection(conString);
    con.Open();

    OracleCommand command = new OracleCommand("SELECT S.IME, S.PREZIME, S.GRAD
                                               FROM SPORTISTA S JOIN CLAN C ON C.ID_SPORTISTE = S.ID
                                               JOIN KLUB K ON K.ID = C.ID_KLUBA
                                               WHERE K.LOKACIJA = 'NIS'
                                               AND C.TIM = 'PRVI'
                                               AND K.ID = :id", con);

    OracleParameter paramId = new OracleParameter("id", OracleDbType.Int32);
    Console.WriteLine("Unesi id kluba");
    paramId.Value = (object)Console.ReadLine();

    command.Parameters.Add(paramId);

    OracleDataReader dr = command.ExecuteReader();

    if(!dr.HasRows)
    {
        return;
    }

    while(dr.Read())
    {
        string ime = dr.GetString(0);
        string prezime = dr.GetString(1);
        string grad = dr.GetString(2);

        Console.WriteLine("Ime: " + ime + " prezime: " + prezime + " grad: "+ grad);
    }
    dr.Close();
}
catch(Exception ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if(con != null && con.State == System.Data.ConnectionState.Open)
    con.Close();
}


--JAN22

--A

--???????

--B

UPDATE FAKTURA SET IZNOS = IZNOS * 1.05
WHERE VALUTA = 'EURO'
AND KOMP_SALJE IN
(
    SELECT ID FROM KOMPANIJA WHERE DRZAVA = "SRBIJA"
)


--C

DELETE FROM FAKTURA
WHERE KOMP_PRIMA IN
(
    SELECT ID FROM KOMPANIJA
    WHERE GRAD = 'NIS'
)
AND NOT EXISTS
(
    SELECT 0
    FROM STAVKA
    WHERE STAVKA.FAKT_ID = FAKTURA.KOMP_PRIMA
)

--D

string conString;
OracleConnection con = null;
try
{
    constring = "Data Source = ...; User Id=...; Password = ...;";
    con = new OracleConnection(conString);
    con.Open();

    OracleCommand command = new OracleCommand("SELECT S.ID, S.NAZIV, S.KOLICINA, S.IZNOS, S.POPUST, S.POREZ, S.FAKT_ID
                                                FROM STAVKA S JOIN FAKTURA F ON F.ID = S.FAKT_ID
                                                WHERE F.KOMP_SALJE = :id
                                                AND YEAR(F.DAT_PLACANJA) = 2021",con);
    OracleParameter paramID = new OracleParameter("id", OracleDbType.Int32);
    Console.WriteLine("Unesi id");
    paramId.Value = Int32.Parse(Console.ReadLine());
    command.Parameters.Add(paramId);

    OracleDataReader dr = command.ExecuteReader();

    if(!dr.HasRows)
    return;

    while(dr.Read())
    {
        int id = dr.GetInt32(0);
        string naziv = dr.GetString(1);

        Console.WriteLine(id + naziv);
    }
    dr.Close();

}
catch(Exception ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if(con != null && con.State == System.Data.ConnectionState.Open)
    con.Close();
}



--SEPT2018

--A

CREATE VIEW KNJIGA_STATISTIKA AS
SELECT P.IME || ' ' || P.PREZIME, P.POL, COUNT(PO.ID) BROJ_POGL, SUM(PO.BROJ_SLIKA) BROJ_SLIKA, AVG(PO.BROJ_TABELA)
FROM KNJIGA K JOIN PISAC P ON K.PISAC_ID = P.ID JOIN POGLAVLJE PO ON PO.KNJIGA_ID = K.ID
WHERE K.NASLOV LIKE '%databases%'
GROUP BY K.ID, P.IME, P.PREZIME 

--B

UPDATE POGLAVLJE SET BROJ_POGL = 
(
    SELECT SUM(BROJ_SLIKA)
    FROM POGLAVLJE P1
    WHERE P1.KNJIGA_ID = POGLAVLJE.KNJIGA_ID
)
WHERE KNJIGA_ID IN 
(
    SELECT DISTINCT KNJIGA_ID 
    FROM POGLAVLJE
    WHERE BROJ_SLIKA > 10  
)


--C

DELETE FROM POGLAVLJE
WHERE ID IN
(
    SELECT ID 
    FROM POGLAVLJE P1 JOIN POGLAVLJE P2 ON P1.ROD_POGL_ID = P2.ID
    GROUP BY P1.ROD_POGL_ID
    HAVING COUNT(P1.ID) > 1
)
AND KNJIGA_ID IN
(
    SELECT ID FROM KNJIGA
    WHERE PISAC_ID IN
    (
        SELECT PISAC_ID 
        FROM KNJIGA
        GROUP BY PISAC_ID
        HAVING COUNT(ID) >= 2
    )
)


--D

Main()
{

string conString;
OracleConnection con = null;
try
{
    constring = "Data Source = ...; User Id=...; Password = ...;";
    con = new OracleConnection(conString);
    con.Open();

    OracleCommand command = new OracleCommand("SELECT K.NAZIV 
                                                FROM KNJIGA K
                                                WHERE K.ID IN
                                                (
                                                    SELECT P.KNJIGA_ID
                                                    FROM POGLAVLJE P
                                                    GROUP BY P.KNJIGA_ID
                                                    HAVING COUNT(P.ID) < 5
                                                )
                                                AND GOD_PUBL = :godina", con);

    OracleParameter paramGodina = new OracleParameter("godina", OracleDbType.Int32);
    Console.WriteLine("Unesi godinu");
    paramGodina.Value = Int32.Parse(Console.ReadLine());
    command.Parameters.Add(paramGodina);

    OracleDataReader dr = command.ExecuteReader();
    if(!dr.HasRows)
    return;

    while(dr.Read())
    {
        string naziv = dr.GetString(0);

        Console.WriteLine("Naziv: " + naziv);
    }
    dr.Close();
}
catch(Exception ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if(con != null && con.State == System.Data.ConnectionState.Open)
    con.Close();
}

}








--D

string conString;
OracleConnection con = null;
try
{
    constring = "Data Source = ...; User Id=...; Password = ...;";
    con = new OracleConnection(conString);
    con.Open();
}
catch(Exception ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if(con != null && con.State == System.Data.ConnectionState.Open)
    con.Close();
}