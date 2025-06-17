
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity xore is
port
(
	a : in std_logic;
    b : in std_logic;
    y : out std_logic
);
end entity;

architecture xora of xore is
begin
y <= a xor b;
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity ore is
port
(
	a : in std_logic;
    b : in std_logic;
    y : out std_logic
);
end entity;

architecture ora of ore is
begin
y<=a or b;
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity kolo is
generic(n : positive := 4);
port
(
	a : in std_logic_vector(n-1 downto 0);
    b : in std_logic_vector(n-1 downto 0);
    c : in std_logic;
    d : out std_logic_vector(n-1 downto 0)
);
end entity;

architecture kolovodja of kolo is
begin

jedan : for i in 0 to n-1 generate
begin

	dva: if (i = 0) generate
    	signal medjusig : std_logic;
    begin
    	
        xor1 : entity work.xore(xora) port map(a(i), b(i), medjusig);
        or1 : entity work.ore(ora) port map(medjusig, c, d(i));
        
    else generate
    	signal medjusig : std_logic;
    begin
    	
        xor2 : entity work.xore(xora) port map(a(i), b(i), medjusig);
        or2 : entity work.ore(ora) port map(medjusig, d(i-1), d(i));
        
    end generate dva;
    
    	

end generate jedan;


end architecture;