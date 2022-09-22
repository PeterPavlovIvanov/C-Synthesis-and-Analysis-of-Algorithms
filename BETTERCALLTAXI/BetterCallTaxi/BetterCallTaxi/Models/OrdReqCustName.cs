using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class OrderRequest
    {
        // Enums
        public enum Columns
        {
            ID = 0, CUSTOMER_ID = 1, ADDRESS_FROM = 2, ADDRESS_TO = 3, ORD_TIME = 4
        }

        // Table Fields
        public Int32 nId;
        public Int32 nCustomerId;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime;

        public bool b_Last_Operation_Status = true;

        public OrderRequest()
        { }

        public OrderRequest(Int32 nId, Int32 nCustomerId, string strAddressFrom, string strAddressTo, DateTime dtOrdTime)
        {
            this.nId = nId;
            this.nCustomerId = nCustomerId;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
        }

        public OrderRequest(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = true;

            if (oSqlDataReader.Read())
            {
                this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
                this.nCustomerId = (Int32)(oSqlDataReader.GetValue((int)Columns.CUSTOMER_ID));
                this.strAddressFrom = (oSqlDataReader.GetValue((int)Columns.ADDRESS_FROM)).ToString();
                this.strAddressTo = (oSqlDataReader.GetValue((int)Columns.ADDRESS_TO)).ToString();
                this.dtOrdTime = (DateTime)(oSqlDataReader.GetValue((int)Columns.ORD_TIME));
            }
            else
            {
                this.b_Last_Operation_Status = false;
            }
        }

    }

    class OrderRequestsReader
    {
        public List<OrderRequest> oOrderRequests;

        public OrderRequestsReader(SqlDataReader oSqlDataReader)
        {
            oOrderRequests = new List<OrderRequest>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                OrderRequest recOrderRequest = new OrderRequest(
                        (Int32)(oSqlDataReader.GetValue((int)OrderRequest.Columns.ID))
                        , (Int32)(oSqlDataReader.GetValue((int)OrderRequest.Columns.CUSTOMER_ID))
                        , (oSqlDataReader.GetValue((int)OrderRequest.Columns.ADDRESS_FROM)).ToString()
                        , (oSqlDataReader.GetValue((int)OrderRequest.Columns.ADDRESS_TO)).ToString()
                        , (DateTime)(oSqlDataReader.GetValue((int)OrderRequest.Columns.ORD_TIME)));

                this.oOrderRequests.Add(recOrderRequest);
            }
        }
    }
    
    // за справката на админа
    class OrdReqCustName
    {
        // Enums
        public enum Columns
        {
            ID = 0, CUSTOMER_NAME = 1, ADDRESS_FROM = 2, ADDRESS_TO = 3, ORD_TIME = 4
        }

        // Table Fields
        public Int32 nId;
        public string strCustName;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime; 

        public bool b_Last_Operation_Status = true;

        public OrdReqCustName()
        { }

        public OrdReqCustName(Int32 nId, string strCustName, string strAddressFrom, string strAddressTo, DateTime dtOrdTime)
        {
            this.nId = nId;
            this.strCustName = strCustName;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
        }

        public OrdReqCustName(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return;

            this.nId = (Int32)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ID));
            this.strCustName = (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.CUSTOMER_NAME)).ToString();
            this.strAddressFrom = (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_FROM)).ToString();
            this.strAddressTo = (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_TO)).ToString();
            this.dtOrdTime = (DateTime)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ORD_TIME));
        }

    }

    class OrdReqCustNameReader
    {
        public List<OrdReqCustName> oOrdReqCustNamesList;

        public OrdReqCustNameReader(SqlDataReader oSqlDataReader)
        {
            oOrdReqCustNamesList = new List<OrdReqCustName>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                OrdReqCustName oOrdReqCustName = new OrdReqCustName(
                        (Int32)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ID))
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.CUSTOMER_NAME)).ToString()
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_FROM)).ToString()
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_TO)).ToString()
                        , (DateTime)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ORD_TIME)));

                this.oOrdReqCustNamesList.Add(oOrdReqCustName);
            }
        }
    }

    // извеждане на заявка за такси в диалог...
    class OrdReqCustNameAndId
    {
        //enums 
        public enum Columns
        {
            ID = 0, CUSTOMER_NAME = 1, CUSTOMER_ID = 2, ADDRESS_FROM = 3, ADDRESS_TO = 4, ORD_TIME = 5
        }

        //Fields
        public OrdReqCustName oOrdReqCustName = new OrdReqCustName();
        public Int32 nCustId;

        public OrdReqCustNameAndId(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return;

            this.oOrdReqCustName.nId = (Int32)(oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.ID));
            this.oOrdReqCustName.strCustName = (oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.CUSTOMER_NAME)).ToString();
            this.nCustId = (Int32)(oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.CUSTOMER_ID));
            this.oOrdReqCustName.strAddressFrom = (oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.ADDRESS_FROM)).ToString();
            this.oOrdReqCustName.strAddressTo = (oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.ADDRESS_TO)).ToString();
            this.oOrdReqCustName.dtOrdTime = (DateTime)(oSqlDataReader.GetValue((int)OrdReqCustNameAndId.Columns.ORD_TIME));
        }
    }

    // за справката на driver home page-а за текущите му поръчки
    class ActiveOrderData
    {
        //enums 
        public enum Columns
        {
            NUM_ORD = 0, ADRESS_FROM = 1, ADRESS_TO = 2, ORD_TIME = 3, IS_DONE = 4
        }

        //Fields
        public Int32 nNumOrd;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime;
        public bool bIsDone;

        public ActiveOrderData()
        { }
        
        public ActiveOrderData(Int32 nNumOrd, string strAddressFrom, string strAddressTo, DateTime dtOrdTime, bool bIsDone)
        {
            this.nNumOrd = nNumOrd;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
            this.bIsDone = bIsDone;
        }

    }

    // четец за справката на driver home page-а за текущите му поръчки
    class ActiveOrderDataReader
    {
        public List<ActiveOrderData> oActiveOrderDataList;

        public ActiveOrderDataReader(SqlDataReader oSqlDataReader)
        {
            this.oActiveOrderDataList = new List<ActiveOrderData>();

            while (oSqlDataReader.Read())
            {
                ActiveOrderData oActiveOrderData = new ActiveOrderData(
                    (Int32)(oSqlDataReader.GetValue((int)ActiveOrderData.Columns.NUM_ORD))
                    , (oSqlDataReader.GetValue((int)ActiveOrderData.Columns.ADRESS_FROM)).ToString()
                    , (oSqlDataReader.GetValue((int)ActiveOrderData.Columns.ADRESS_TO)).ToString()
                    , (DateTime)(oSqlDataReader.GetValue((int)ActiveOrderData.Columns.ORD_TIME))
                    , (Boolean)(oSqlDataReader.GetValue((int)ActiveOrderData.Columns.IS_DONE))
                );

                this.oActiveOrderDataList.Add(oActiveOrderData);
            }
        }
    }

}
