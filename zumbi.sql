USE zumbi;

-- this is the create user statement
INSERT INTO `zumbi`.`bag` (`size`,`itens`)VALUES(12,'{"axe", "mace", "helmet"}');
SET @bagid = LAST_INSERT_ID();
INSERT INTO `zumbi`.`player`(`name`, `password`, `xp`, `idbag`) VALUES ("cohen", "cohen", 0, @bagid);

-- update xp query
UPDATE `zumbi`.`player` SET `player`.`xp`=10 WHERE `player`.`idplayer`=1;

-- update bag query
UPDATE `zumbi`.`bag` SET `bag`.`itens`='{"knife","pistol","mana","potion"}' WHERE `bag`.`idbag`=102;

-- delete query
delete from `zumbi`.`player` where `player`.`idplayer`=6;
delete from `zumbi`.`bag` where `bag`.`idbag`=107;
delete from `zumbi`.`build` where id=2;

select * from player inner join bag;
select * from player;
select * from bag;
select * from build order by location asc;
select * from enemy;


-- ------------------
-- admin querys
-- ------------------

INSERT INTO `zumbi`.`build` (`name`, `location`, `size`, `theft`, `description`) VALUES ("Nut Peak", 2, 4, 2, "Some rocks, some cactus, near from the forest and maybe the city");
INSERT INTO `zumbi`.`enemy` (`name`, `xpgain`) VALUES ("infected squirrel", 1);

-- ALTER TABLE `zumbi`.`enemy` MODIFY `xpgain` INTEGER;
