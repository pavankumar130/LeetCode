# Write your MySQL query statement below
select product_name, year, price 
    from sales INNER JOIN product on 
        sales.product_id = Product.product_id;