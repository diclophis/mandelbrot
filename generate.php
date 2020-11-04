<?php

list($left_x, $lower_y, $right_x, $upper_y) = (explode(',', $_REQUEST['BBOX']));

$tmp = sprintf("/tmp/%.9f.%.9f.%.9f.%.9f.jpeg", $left_x, $lower_y, $right_x, $upper_y);

if (!file_exists($tmp)) {
  $cmd = sprintf("nice -n 19 /var/www/html/jbardin-fractal %.9f %.9f %.9f %.9f %s", $left_x, $lower_y, $right_x, $upper_y, $tmp);
  system($cmd);
}

header('Content-Type: image/jpeg');

readfile($tmp);

?>
