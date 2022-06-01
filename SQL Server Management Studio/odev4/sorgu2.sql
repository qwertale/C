create view Product_view (Product_no, Description, Profit_percent,Unit_measure, Qty_on_hand)
as select Product_no, Description, Profit_percent, Unit_measure, Qty_on_hand 
from PRODUCT_MASTER