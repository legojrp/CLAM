<?php 
  class CLAM {
  private $path;
  function __construct($path){
    $this->path = $path;
  }
   function writeToProperty($property, $replacement){
       $file = fopen($this->path, "r");
  		 $text, $pre, $post, $changed;
    	 $preOrPost = 0;
    		while (feof($file)){
            $text = fgets($file);
      			if (substr($text, 0, find($text, ": ") == property){
         			$preOrPost = 1;
        			continue;
      			}
      			else if ($preOrPost == 0){
        			$pre += $text . "\n";
      			}
      			else if (preOrPost == 1){
        			$post += $text . "\n";
      			}

    		}
    		$changed = $pre . $property . ": " . $replacement + "\n" . $post;
    		fclose($file);
    		$file fopen($this->path, "");
    		fwrite($file, $changed);
    		fclose($file);
   }
   function readFromProperty($property){
   $file = fopen($this->path, "r");
   $text = "";
   $returnstring = "";
   while (!feof($file)){
   $text = fgets($file);
   $substr = substr($text,0, find($text, ": "))
   if ($substr == $property){
      $returnstring = substr($text, strlen($substr) + 2);
      
   }
    else ($substr != $property) {
    $returnstring = null;
    }
    
   }
     return $returnstring;
   }
   function createProperty($property, $content){
        $file = fopen($this->path, "a"){
        fwrite($file, $property . ": " . $content . "\n");
        fclose($file);
   }
   
  }
?> 
