namespace Pipeline;

interface PipelineInterface
{
	public function pipe(var operation);

	public function process(var playload);
}