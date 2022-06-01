select "NAME",Product_no from CLIENT_MASTER
Join SALES_ORDER on CLIENT_MASTER.client_no = SALES_ORDER.Client_no
Join SALES_ORDER_DETAILS
on SALES_ORDER_DETAILS.S_order_no = SALES_ORDER.S_order_no
where datediff(day, S_order_Date,DELY_DATE) > 10
group by name ,Product_no