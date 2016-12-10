namespace Pipeline;

interface ProcessorInterface
{
	public function process(array! stages, var playload);
}