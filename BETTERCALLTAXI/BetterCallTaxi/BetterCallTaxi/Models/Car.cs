using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class Car
    {
        // Enums
        public enum Columns
        {
            KOD_TAXI = 0, REG_NOMER = 1, MANUFACTURER_ID = 2, SEATS = 3, LUGGAGE = 4, DRIVER_ID = 5
        }

        // Полета в таблицата CUSTOMERS
        public Int32 nKodTaxi;
        public string strRegNomer;
        public Int32 nManufacturerId;
        public Byte bySeats;
        public bool bLugage;
        public Int32 nDriverId;

        public bool b_Last_Operation_Status = true;

        public Car()
        {
            this.nKodTaxi = 0;
            this.strRegNomer = "";
            this.nManufacturerId = 0;
            this.bySeats = 0;
            this.bLugage = false;
            this.nDriverId = 0;
        }

        public Car(Int32 nKodTaxi, string strRegNomer, Int32 nManufacturerId, Byte bySeats, bool bLugage, Int32 nDriverId)
        {
            this.nKodTaxi = nKodTaxi;
            this.strRegNomer = strRegNomer;
            this.nManufacturerId = nManufacturerId;
            this.bySeats = bySeats;
            this.bLugage = bLugage;
            this.nDriverId = nDriverId;
        }
    }

    class CarsAndOwners
    {
        // Enums
        public enum Columns
        {
            KOD_TAXI = 0, REG_NOMER = 1, MANUFACTURER = 2, SEATS = 3, LUGGAGE = 4, DRIVER = 5
        }

        public Car recCar;
        public string strManufacturer;
        public string strDriver;

        public CarsAndOwners()
        {
            this.recCar = new Car();
            this.strManufacturer = "";
            this.strDriver = "";
        }

        public CarsAndOwners(Car recCar, string strManufacturer, string strDriver)
        {
            this.recCar = recCar;
            this.strManufacturer = strManufacturer;
            this.strDriver = strDriver;
        }
    }

    class CarsAndOwnersReader
    {
        public List<CarsAndOwners> oCarsAndOwnersList;
        public CarsAndOwnersReader(SqlDataReader oSqlDataReader)
        {
            oCarsAndOwnersList = new List<CarsAndOwners>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                CarsAndOwners oCarsAndOwners = new CarsAndOwners(new Car(
                        (Int32)(oSqlDataReader.GetValue((int)Car.Columns.KOD_TAXI))
                        , (oSqlDataReader.GetValue((int)Car.Columns.REG_NOMER)).ToString()
                        , 0
                        , (Byte)(oSqlDataReader.GetValue((int)Car.Columns.SEATS))
                        , (System.Boolean)(oSqlDataReader.GetValue((int)Car.Columns.LUGGAGE))
                        , 0
                    ), (string)(oSqlDataReader.GetValue((int)CarsAndOwners.Columns.MANUFACTURER))
                     , (string)(oSqlDataReader.GetValue((int)CarsAndOwners.Columns.DRIVER))
                );

                this.oCarsAndOwnersList.Add(oCarsAndOwners);
            }
        }
    }

}
