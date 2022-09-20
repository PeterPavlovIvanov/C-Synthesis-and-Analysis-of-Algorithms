using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class Order
    {
        // Enums
        public enum Columns
        {
            NUM_ORD = 0, KOD_TAXI = 1, ADDRESS_FROM = 2, ADDRESS_TO = 3, ORD_TIME = 4, DRIVING_TIME = 5, DISTANCE = 6, FARE = 7, CUSTOMER_ID = 8, IS_DONE = 9
        }

        // Полета в таблицата CUSTOMERS
        public Int32 nNumOrd;
        public Int32 nKodTaxi;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime;
        public TimeSpan tDrivingTime;
        public Double dDistance;
        public Double dFare;
        public Int32 nCustomerId;
        public bool bIsDone;

        public bool b_Last_Operation_Status = true;

        public Order()
        { }

        public Order(Int32 nNumOrd, Int32 nKodTaxi, string strAddressFrom, string strAddressTo
            , DateTime dtOrdTime, TimeSpan tDrivingTime, Double dDistance, Double dFare, Int32 nCustomerId, bool bIsDone)
        {
            this.nNumOrd = nNumOrd;
            this.nKodTaxi = nKodTaxi;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
            this.tDrivingTime = tDrivingTime;
            this.dDistance = dDistance;
            this.dFare = dFare;
            this.nCustomerId = nCustomerId;
            this.bIsDone = bIsDone;
        }

        public string GetOrderStatus()
        {
            return this.bIsDone ? GlobalConstants.ORDER_DONE : GlobalConstants.ORDER_ACTIVE ; 
        }
    }


    class OrdersViewModel
    {
        // Enums
        public enum Columns
        {
            NUM_ORD = 0, REG_NOMER = 1, MANUFACTURER = 2, ADDRESS_FROM = 3, ADDRESS_TO = 4,
            ORD_TIME = 5, DRIVING_TIME = 6, DISTANCE = 7, FARE = 8, CUSTOMER_NAME = 9, IS_DONE = 10
        }

        public Order recOrder;
        public string strRegNomer;
        public string strManufacturer;
        public string strCustName;

        public OrdersViewModel()
        { }

        public OrdersViewModel(Order recOrder, string strRegNomer, string strManufacturer, string strCustName)
        {
            this.recOrder = recOrder;
            this.strRegNomer = strRegNomer;
            this.strManufacturer = strManufacturer;
            this.strCustName = strCustName;
        }

    }

    class OrdersViewModelReader
    {
        public List<OrdersViewModel> oOrderViewModels;

        public OrdersViewModelReader(SqlDataReader oSqlDataReader)
        {
            oOrderViewModels = new List<OrdersViewModel>();
            Read_Order_Models(oSqlDataReader);
        }

        public void Read_Order_Models(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                OrdersViewModel oOrdersViewModel = new OrdersViewModel(new Order(
                       (Int32)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.NUM_ORD))
                       , 0
                       , (oSqlDataReader.GetValue((int)OrdersViewModel.Columns.ADDRESS_FROM)).ToString()
                       , (oSqlDataReader.GetValue((int)OrdersViewModel.Columns.ADDRESS_TO)).ToString()
                       , (DateTime)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.ORD_TIME))
                       , (TimeSpan)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.DRIVING_TIME))
                       , (Double)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.DISTANCE))
                       , (Double)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.FARE))
                       , 0
                       , (Boolean)(oSqlDataReader.GetValue((int)OrdersViewModel.Columns.IS_DONE)) )
                    , (oSqlDataReader.GetValue((int)OrdersViewModel.Columns.REG_NOMER)).ToString()
                    , (oSqlDataReader.GetValue((int)OrdersViewModel.Columns.MANUFACTURER)).ToString()
                    , (oSqlDataReader.GetValue((int)OrdersViewModel.Columns.CUSTOMER_NAME)).ToString()
                );

                this.oOrderViewModels.Add(oOrdersViewModel);
            }
        }
    }

}
