<?php
	$data = fopen('new.txt', 'w') or die('Unable to open file!');
	$df1 = $_POST['df1'];
	$df2 = $_POST['df2'];
	$df3 = $_POST['df3'];
	$df4 = $_POST['df4'];
	$df5 = $_POST['df5'];
	$df6 = $_POST['df6'];
	$df7 = $_POST['df7'];
	$df8 = $_POST['df8'];
	
	fwrite($data, $df1 . " " . $df2 . " " . $df3 . " " . $df4 . " " . $df5 . " " . $df6 . " " . $df7 . " " . $df8);
	fclose($data);
?>