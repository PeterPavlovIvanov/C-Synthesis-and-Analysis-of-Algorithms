using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class Manufacturer
    {
        // enums
        public enum Columns
        { ID = 0, NAME = 1 }

        // Fields in Database
        public Int32 nId;
        public string strName;

        public Manufacturer()
        { }

        public Manufacturer(Int32 nId, string strName)
        {
            this.nId = nId;
            this.strName = strName;
        }
    }

    class ManufacturersReader
    {
        public List<Manufacturer> oManufacturersList;

        public ManufacturersReader(SqlDataReader oSqlDataReader)
        {
            oManufacturersList = new List<Manufacturer>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                Manufacturer recManufacturer = new Manufacturer(
                    (Int32)(oSqlDataReader.GetValue((int)Manufacturer.Columns.ID))
                    , (oSqlDataReader.GetValue((int)Manufacturer.Columns.NAME)).ToString());

                this.oManufacturersList.Add(recManufacturer);
            }
        }
    }

}
