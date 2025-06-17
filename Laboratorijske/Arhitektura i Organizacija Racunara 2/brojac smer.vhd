library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity brojac is
generic(n : natural := 4);
port(
	smer : in std_logic;
    ce : in std_logic;
    wr : in std_logic;
    din : in integer;
    clk : in std_logic;
    count : out std_logic_vector(n-1 downto 0)
);
end entity;

architecture br of brojac is

begin
	
    process(clk)
    variable internal : integer range 0 to (2**n-1);
    begin
    	
        if(clk'event and clk = '1') then
        	if(ce = '1') then
            	if(smer = '1') then
            		if(internal = 2**n-1) then
                		if(wr = '1') then
                        	internal := din;
                        else
                        	internal := 0;
                        end if;
                    else
                    	internal := internal +1;
                    end if;
                else
                	if(internal = 0) then
                		if(wr = '1') then
                    		internal := din;
                    	else
                    		internal := 2**n-1;
                    	end if;
                    else
                    	internal := internal - 1;
                    end if;--int0
           		end if;--smer
               else
               		internal := 0;
               end if; --ce
       	end if;
    
    count <= std_logic_vector(to_unsigned(internal,n));
    end process;
   
end architecture;