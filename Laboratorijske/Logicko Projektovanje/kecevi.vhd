
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity specijalac is
generic(n: positive := 4);
port
(
	clock : in std_logic;
    reset : in std_logic;
    stanje : out std_logic_vector(n-1 downto 0)
);
end entity;

architecture specc of specijalac is
begin

	process(clock) is
    	variable trenutno : std_logic_vector(n-1 downto 0);
        variable brojcanik : integer range 1 to n;
    begin
    
    	if(clock'event and clock = '1') then
        	
            if(reset = '1') then
            	brojcanik := 1;
                trenutno := ('1', others=>'0');
            
            else
            	if(brojcanik = n) then
                	trenutno := ('1', others=>'0');
                    brojcanik := 1;
                else
                	trenutno := '1' & trenutno(n-1 downto 1);
                    brojcanik := brojcanik + 1;
                end if;
                
            end if;    
            
        end if;
    	
    stanje <= trenutno;
    end process;

end architecture;
